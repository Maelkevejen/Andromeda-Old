#include "manager.hpp"

#include "andromeda/core/system/log/log.hpp"

#include <GLFW/glfw3.h>

#include <algorithm>
#include <execution>

namespace Andromeda::System::Linux::Graphics::Display {
    Manager::Manager(Andromeda::System::Linux::Graphics::Display::Manager::Configuration configuration) : m_Configuration({configuration}) {
        ANDROMEDA_CORE_INFO("Constructing a Linux Display Manager.");
        initialize();
        callbacks();
    }

    Manager::~Manager() {
        ANDROMEDA_CORE_INFO("Terminating a Linux Display Manager.");
        glfwTerminate();
    }

    void Manager::initialize() {
        [[ maybe_unused ]] auto glfw = glfwInit();
        ANDROMEDA_CORE_ASSERT_MESSAGE(glfw == GLFW_TRUE, "Failed to initialize GLFW, code: {0}.", glfw);
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        int count = 0;
        auto monitors = glfwGetMonitors(& count);

        for (int monitor = 0; monitor < count; monitor++) m_Monitors.push_back(std::make_unique<Andromeda::System::Linux::Graphics::Display::Monitor>(Andromeda::System::Graphics::Display::Monitor::Configuration {.callbacks = m_Configuration.callbacks.monitor}, monitors[monitor]));
        ANDROMEDA_CORE_INFO("Initialzed {0} monitors.", m_Monitors.size());
    }

    void Manager::update() {
        ANDROMEDA_CORE_TRACE("Updating Linux Display Manager.");
        glfwPollEvents();
        std::for_each(std::execution::par_unseq, std::begin(m_Windows), std::end(m_Windows), [](auto & window) {
            window->update();
        });
    }

    bool Manager::pressed(Andromeda::System::Input::Code::Keyboard::Key key) const {
        ANDROMEDA_CORE_TRACE("Query focused window keystate.");
        return m_Windows.front()->pressed(key);
    }

    bool Manager::pressed(Andromeda::System::Input::Code::Keyboard::Mod mod) const {
        ANDROMEDA_CORE_TRACE("Query focused window keymod state.");
        return m_Windows.front()->pressed(mod);
    }

    bool Manager::pressed(Andromeda::System::Input::Code::Mouse::Button button) const {
        ANDROMEDA_CORE_TRACE("Query focused window mouse button state.");
        return m_Windows.front()->pressed(button);
    }

    Andromeda::System::Structure::Duo<double> Manager::mouse() const {
        ANDROMEDA_CORE_TRACE("Query focused window mouse state.");
        return m_Windows.front()->mouse();
    }

    void Manager::create(Andromeda::System::Graphics::Display::Window::Configuration configuration) {
        ANDROMEDA_CORE_TRACE("Creating a Linux Window.");
        configuration.callbacks = m_Configuration.callbacks.window;
        {
            m_Windows_Mutex.lock();
            m_Windows.push_back(std::make_unique<Andromeda::System::Linux::Graphics::Display::Window>(configuration));
            m_Windows_Mutex.unlock();
        }
    }

    void Manager::callbacks() {
        ANDROMEDA_CORE_INFO("Setting Linux Display Manager callbacks.");

        m_Configuration.callbacks.window->close.listen([&](Andromeda::System::Event::Window::Close, const Andromeda::System::Graphics::Display::Window * window) {
            ANDROMEDA_CORE_INFO("Removing Window from Display Stack.");
            {
                m_Windows_Mutex.lock();
                std::erase_if(m_Windows, [& window](const auto & m_Window) {
                    return window == m_Window.get();
                });
                // TODO__ANDROMEDA: Terminating the display manager when there are no windows left might not be desired. TAGS: __ANDROMEDA__DESIGN__
                if (m_Windows.empty()) {
                    ANDROMEDA_CORE_INFO("All Windows closed, calling terminate on Linux Display Manager.");
                    Andromeda::System::Event::Instance::Display::Terminate event;
                    m_Configuration.callbacks.display->terminate.transmit(event, this);
                }
                m_Windows_Mutex.unlock();
            }
        });

        m_Configuration.callbacks.window->focus.listen([&](Andromeda::System::Event::Window::Focus, const Andromeda::System::Graphics::Display::Window * window) {
            {
                m_Windows_Mutex.lock();
                auto pivot = std::find_if(std::execution::par_unseq, std::begin(m_Windows), std::end(m_Windows), [&](const auto & m_Window) {
                    return window == m_Window.get();
                });
                if (pivot != std::end(m_Windows)) {
                    ANDROMEDA_CORE_INFO("Moving Window to front of display stack.");
                    std::rotate(std::begin(m_Windows), pivot, pivot + 1);
                }
                m_Windows_Mutex.unlock();
            }
        });
    }
} /* Andromeda::System::Graphics::Display */

namespace Andromeda::System::Graphics::Display {
    std::unique_ptr<Manager> Manager::instantiate(Manager::Configuration configuration) {
        ANDROMEDA_CORE_INFO("Instantiating a Linux Display Manager.");
        return std::make_unique<Andromeda::System::Linux::Graphics::Display::Manager>(configuration);
    }
} /* Andromeda::System::Graphics::Display */
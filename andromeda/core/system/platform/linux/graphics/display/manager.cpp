#include "manager.hpp"

#include "andromeda/core/system/log/log.hpp"

#include <GLFW/glfw3.h>

#include <execution>

namespace Andromeda::System::Linux::Graphics::Display {
    Manager::Manager(Andromeda::System::Linux::Graphics::Display::Manager::Configuration configuration) : m_Configuration({configuration}) {
        ANDROMEDA_CORE_TRACE("Constructing a Linux Display Manager.");
        initialize();
    }
    Manager::~Manager() {
        glfwTerminate();
    }
    void Manager::initialize() {
        [[ maybe_unused ]] auto glfw = glfwInit();
        ANDROMEDA_CORE_ASSERT_MESSAGE(glfw == GLFW_TRUE, "Failed to initialize GLFW, code: {0}.", glfw);
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        int count = 0;
        auto monitors = glfwGetMonitors(&count);
        for (int monitor = 0; monitor < count; monitor++) m_Monitors.push_back(std::make_unique<Andromeda::System::Linux::Graphics::Display::Monitor>(monitors[monitor]));
        ANDROMEDA_CORE_INFO("Initialzed {0} monitors.", m_Monitors.size());
    }
    void Manager::update() {
        ANDROMEDA_CORE_TRACE("Updating Linux Display Manager.");
        std::for_each(std::execution::par, std::begin(m_Windows), std::end(m_Windows), [](auto & window) {
            window->update();
        });
        std::for_each(std::execution::par, std::begin(m_Monitors), std::end(m_Monitors), [](auto & monitor) {
            monitor->update();
        });
    }
    void Manager::create(Andromeda::System::Graphics::Display::Window::Configuration configuration) {
        ANDROMEDA_CORE_TRACE("Creating a Linux Window.");
        configuration.callbacks = m_Configuration.callbacks.window;
        m_Windows.push_back(std::make_unique<Andromeda::System::Linux::Graphics::Display::Window>(configuration));
    }
} /* Andromeda::System::Graphics::Display */

namespace Andromeda::System::Graphics::Display {
    std::unique_ptr<Manager> Manager::instantiate(Manager::Configuration configuration) {
        return std::make_unique<Andromeda::System::Linux::Graphics::Display::Manager>(configuration);
    }
} /* Andromeda::System::Graphics::Display */
#include "window.hpp"

#include "andromeda/core/system/log/log.hpp"

namespace Andromeda::System::Linux::Graphics::Display {
    Window::Window(Window::Configuration configuration) : m_Configuration({configuration}) {
        ANDROMEDA_CORE_INFO("Constructing Window {0} @ [{1}, {2}] with resolution [{3}, {4}].", m_Configuration.title, m_Configuration.position.x, m_Configuration.position.y, m_Configuration.viewport.width, m_Configuration.viewport.height);
        initialize();
    }

    Window::~Window() {
        ANDROMEDA_CORE_INFO("Destroying Window {0}.", m_Configuration.title);
        if(m_Native) glfwDestroyWindow(m_Native); 
    }

    void Window::initialize() {
        glfwWindowHint(GLFW_DECORATED, m_Configuration.options >= Options::Decorated);
        glfwWindowHint(GLFW_RESIZABLE, m_Configuration.options >= Options::Resizable);
        glfwWindowHint(GLFW_VISIBLE, m_Configuration.options >= Options::Visible);
        glfwWindowHint(GLFW_FLOATING, m_Configuration.options >= Options::Floating);

        if (m_Configuration.options >= Window::Options::Subscreen) subscreen();
        if (m_Configuration.options >= Window::Options::Fullscreen) fullscreen();

        ANDROMEDA_CORE_ASSERT(m_Native != nullptr, "Window not created, native pointer is nullified.");
        
        ANDROMEDA_CORE_WARN("Stored Window {0}'s *this* pointer in configuration state.", m_Configuration.title);
        m_Configuration.window = this;
        glfwSetWindowUserPointer(m_Native, & m_Configuration);

        callbacks();
    }

    void Window::update() {
        ANDROMEDA_CORE_TRACE("Window {0} update().", m_Configuration.title);
    }

    bool Window::pressed(Andromeda::System::Input::Code::Keyboard::Key key) const {
        ANDROMEDA_CORE_TRACE("Window {0} key {1} state query", m_Configuration.title, key);
        return glfwGetKey(m_Native, static_cast<int>(key)) == GLFW_PRESS;
    }

    bool Window::pressed(Andromeda::System::Input::Code::Keyboard::Mod mod) const {
        ANDROMEDA_CORE_TRACE("Window {0} keymod {1} state query", m_Configuration.title, mod);
        return glfwGetKey(m_Native, static_cast<int>(mod)) == GLFW_PRESS;
    }

    bool Window::pressed(Andromeda::System::Input::Code::Mouse::Button button)  const {
        ANDROMEDA_CORE_TRACE("Window {0} button {1} state query", m_Configuration.title, button);
        return glfwGetMouseButton(m_Native, static_cast<int>(button)) == GLFW_PRESS;
    }

    Andromeda::System::Structure::Duo<double> Window::mouse() const {
        ANDROMEDA_CORE_TRACE("Window {0} mouse position state query", m_Configuration.title, button);
        Andromeda::System::Structure::Duo<double> position;
        glfwGetCursorPos(m_Native, & position.α, & position.β);
        return position;
    }

    void Window::subscreen() {
        ANDROMEDA_CORE_INFO("Window {0} as subscreen on undefined monitor.", m_Configuration.title);
        m_Native = glfwCreateWindow(m_Configuration.viewport.width, m_Configuration.viewport.height, m_Configuration.title.data(), nullptr, nullptr);
    }
    void Window::fullscreen() {
        ANDROMEDA_CORE_INFO("Window {0} as fullscreen on Monitor {1}.", m_Configuration.title, "Undefined");
    }
    void Window::callbacks() {
        ANDROMEDA_CORE_INFO("Setting Window {0} callbacks.", m_Configuration.title);

        glfwSetWindowPosCallback(m_Native, [](GLFWwindow * window, int x, int y) {
            auto configuration = static_cast<Window::Configuration *>(glfwGetWindowUserPointer(window));
            configuration->position = {x, y};
            Andromeda::System::Event::Window::Move event({x, y});
            configuration->callbacks->move.transmit(event, configuration->window);
            ANDROMEDA_CORE_INFO("Moved Window {0} to ({1}, {2}).", configuration->title, configuration->position.x, configuration->position.y);
        });

        glfwSetWindowSizeCallback(m_Native, [](GLFWwindow * window, int x, int y) {
            auto configuration = static_cast<Window::Configuration *>(glfwGetWindowUserPointer(window));
            configuration->viewport = {x, y};
            Andromeda::System::Event::Window::Resize event({x, y});
            configuration->callbacks->resize.transmit(event, configuration->window);
            ANDROMEDA_CORE_INFO("Resized Window {0} to ({1} x {2}).", configuration->title, configuration->viewport.width, configuration->viewport.height);
        });

        glfwSetWindowCloseCallback(m_Native, [](GLFWwindow * window) {
            auto configuration = static_cast<Window::Configuration *>(glfwGetWindowUserPointer(window));
            Andromeda::System::Event::Window::Close event;
            ANDROMEDA_CORE_INFO("Closing Window {0}.", configuration->title);
            configuration->callbacks->close.transmit(event, configuration->window);
        });

        glfwSetWindowRefreshCallback(m_Native, [](GLFWwindow * window) {
            auto configuration = static_cast<Window::Configuration *>(glfwGetWindowUserPointer(window));
            Andromeda::System::Event::Window::Refresh event;
            configuration->callbacks->refresh.transmit(event, configuration->window);
            ANDROMEDA_CORE_INFO("Refreshed Window {0}.", configuration->title);
        });

        glfwSetWindowFocusCallback(m_Native, [](GLFWwindow * window, int focused) {
            auto configuration = static_cast<Window::Configuration *>(glfwGetWindowUserPointer(window));

            switch (focused) {
                case GLFW_TRUE: {
                    Andromeda::System::Event::Window::Focus event;
                    configuration->callbacks->focus.transmit(event, configuration->window);
                    ANDROMEDA_CORE_INFO("Focused Window {0}.", configuration->title);
                    break;
                }
                case GLFW_FALSE: {
                    Andromeda::System::Event::Window::Defocus event;
                    configuration->callbacks->defocus.transmit(event, configuration->window);
                    ANDROMEDA_CORE_INFO("Defocused Window {0}.", configuration->title);
                    break;
                }
            }
        });

        glfwSetWindowMaximizeCallback(m_Native, [](GLFWwindow * window, int maximized) {
            auto configuration = static_cast<Window::Configuration *>(glfwGetWindowUserPointer(window));

            switch (maximized) {
                case GLFW_TRUE: {
                    Andromeda::System::Event::Window::Maximize event;
                    configuration->callbacks->maximize.transmit(event, configuration->window);
                    ANDROMEDA_CORE_INFO("Maximized Window {0}.", configuration->title);
                    break;
                }
                case GLFW_FALSE: {
                    Andromeda::System::Event::Window::Restore event;
                    configuration->callbacks->restore.transmit(event, configuration->window);
                    ANDROMEDA_CORE_INFO("Restored Window {0}.", configuration->title);
                    break;
                }
            }
        });

        glfwSetWindowIconifyCallback(m_Native, [](GLFWwindow * window, int iconified) {
            auto configuration = static_cast<Window::Configuration *>(glfwGetWindowUserPointer(window));

            switch (iconified) {
                case GLFW_TRUE: {
                    Andromeda::System::Event::Window::Minimize event;
                    configuration->callbacks->minimize.transmit(event, configuration->window);
                    ANDROMEDA_CORE_INFO("Minimized Window {0}.", configuration->title);
                    break;
                }
                case GLFW_FALSE: {
                    Andromeda::System::Event::Window::Restore event;
                    configuration->callbacks->restore.transmit(event, configuration->window);
                    ANDROMEDA_CORE_INFO("Restored Window {0}.", configuration->title);
                    break;
                }
            }
        });

        glfwSetKeyCallback(m_Native, [](GLFWwindow * window, int key, int /*scancode*/, int action, int mods) {
            auto configuration = static_cast<Window::Configuration *>(glfwGetWindowUserPointer(window));

            switch (action) {
                case GLFW_PRESS: {
                    Andromeda::System::Event::Keyboard::Key::Press event(static_cast<Andromeda::System::Input::Code::Keyboard::Key>(key), static_cast<Andromeda::System::Input::Code::Keyboard::Mod>(mods), 0);
                    configuration->callbacks->input.keyboard.press.transmit(event, configuration->window);
                    ANDROMEDA_CORE_INFO("Window {0} keypressed {1} with mods {2}.", configuration->title, key, mods);
                    break;
                }
                case GLFW_RELEASE: {
                    Andromeda::System::Event::Keyboard::Key::Release event(static_cast<Andromeda::System::Input::Code::Keyboard::Key>(key), static_cast<Andromeda::System::Input::Code::Keyboard::Mod>(mods));
                    configuration->callbacks->input.keyboard.release.transmit(event, configuration->window);
                    ANDROMEDA_CORE_INFO("Window {0} keyreleased {1} with mods {2}.", configuration->title, key, mods);
                    break;
                }
                case GLFW_REPEAT: {
                    Andromeda::System::Event::Keyboard::Key::Press event(static_cast<Andromeda::System::Input::Code::Keyboard::Key>(key), static_cast<Andromeda::System::Input::Code::Keyboard::Mod>(mods), 1);
                    configuration->callbacks->input.keyboard.press.transmit(event, configuration->window);
                    ANDROMEDA_CORE_INFO("Window {0} repeat keypressed {1} with mods {2}.", configuration->title, key, mods);
                    break;
                }
            }
        });

        glfwSetCharCallback(m_Native, [](GLFWwindow * window, unsigned int key) {
            auto configuration = static_cast<Window::Configuration *>(glfwGetWindowUserPointer(window));
            Andromeda::System::Event::Keyboard::Key::Type event(static_cast<Andromeda::System::Input::Code::Keyboard::Key>(key));
            configuration->callbacks->input.keyboard.type.transmit(event, configuration->window);
            ANDROMEDA_CORE_TRACE("Window {0} keytyped {1}.", configuration->title, key);
        });

        glfwSetCursorPosCallback(m_Native, [](GLFWwindow * window, double x_Position, double y_Position) {
            auto configuration = static_cast<Window::Configuration *>(glfwGetWindowUserPointer(window));
            Andromeda::System::Event::Mouse::Move event({x_Position, y_Position});
            configuration->callbacks->input.mouse.move.transmit(event, configuration->window);
            ANDROMEDA_CORE_TRACE("Window {0} mouse moved to ({1}, {2}).", configuration->title, x_Position, y_Position);
        });

        glfwSetScrollCallback(m_Native, [](GLFWwindow * window, double x_Offset,  double y_Offset) {
            auto configuration = static_cast<Window::Configuration *>(glfwGetWindowUserPointer(window));
            Andromeda::System::Event::Mouse::Scroll event({x_Offset, y_Offset});
            configuration->callbacks->input.mouse.scroll.transmit(event, configuration->window);
            ANDROMEDA_CORE_INFO("Window {0} mouse scrolled ({1}, {2}).", configuration->title, x_Offset, y_Offset);
        });

        glfwSetMouseButtonCallback(m_Native, [](GLFWwindow * window, int button, int action, int mods) {
            auto configuration = static_cast<Window::Configuration *>(glfwGetWindowUserPointer(window));

            switch (action) {
                case GLFW_PRESS: {
                    Andromeda::System::Event::Mouse::Button::Press event(static_cast<Andromeda::System::Input::Code::Mouse::Button>(button), static_cast<Andromeda::System::Input::Code::Keyboard::Mod>(mods));
                    configuration->callbacks->input.mouse.press.transmit(event, configuration->window);
                    ANDROMEDA_CORE_INFO("Window {0} mouse button pressed {1} with mods {2}.", configuration->title, button, mods);
                    break;
                }
                case GLFW_RELEASE: {
                    Andromeda::System::Event::Mouse::Button::Release event(static_cast<Andromeda::System::Input::Code::Mouse::Button>(button), static_cast<Andromeda::System::Input::Code::Keyboard::Mod>(mods));
                    configuration->callbacks->input.mouse.release.transmit(event, configuration->window);
                    ANDROMEDA_CORE_INFO("Window {0} mouse button released {1} with mods {2}.", configuration->title, button, mods);
                    break;
                }
            }
        });
    }
} /* Andromeda::System::Linux::Graphics::Display */
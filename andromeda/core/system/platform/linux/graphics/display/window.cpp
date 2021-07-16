#include "window.hpp"

#include "andromeda/core/system/log/log.hpp"

namespace Andromeda::System::Linux::Graphics::Display {
    Window::Window(Window::Configuration configuration) : m_Configuration({configuration}) {
        ANDROMEDA_CORE_INFO("Constructing Window {0} @ [{1}, {2}] with resolution [{3, 4}].", m_Configuration.title, m_Configuration.position.x, m_Configuration.position.y, m_Configuration.viewport.width, m_Configuration.viewport.height);
        initialize();
    }

    Window::~Window() {
        ANDROMEDA_CORE_INFO("Destroying window {0}.", m_Configuration.title);
        if (m_Native) glfwDestroyWindow(m_Native);
    }

    void Window::initialize() {
        glfwWindowHint(GLFW_DECORATED, m_Configuration.options >= Options::Decorated);
        glfwWindowHint(GLFW_RESIZABLE, m_Configuration.options >= Options::Resizable);
        glfwWindowHint(GLFW_VISIBLE, m_Configuration.options >= Options::Visible);
        glfwWindowHint(GLFW_FLOATING, m_Configuration.options >= Options::Floating);

        if (m_Configuration.options >= Window::Options::Subscreen) subscreen();
        if (m_Configuration.options >= Window::Options::Fullscreen) fullscreen();

        ANDROMEDA_CORE_ASSERT(m_Native != nullptr, "Window not created, native pointer is nullified.");
        glfwSetWindowUserPointer(m_Native, & m_Configuration);

        callbacks();
    }

    void Window::update() {
        ANDROMEDA_CORE_TRACE("Window {0} update().", m_Configuration.title);
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
        glfwSetWindowCloseCallback(m_Native, [](GLFWwindow * window) {
            auto configuration = static_cast<Window::Configuration *>(glfwGetWindowUserPointer(window));
            ANDROMEDA_CORE_TRACE("Closing Window {0}.", configuration->title);
            Andromeda::System::Event::Window::Close event;
            configuration->callbacks->close.transmit(event);
        });
    }
} /* Andromeda::System::Linux::Graphics::Display */
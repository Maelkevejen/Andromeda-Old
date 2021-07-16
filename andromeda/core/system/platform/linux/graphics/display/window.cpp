#include "window.hpp"

#include "andromeda/core/system/event/type/window.hpp"

#include "andromeda/core/system/log/log.hpp"

namespace Andromeda::System::Linux::Graphics::Display {
    Window::Window(Window::Configuration configuration) : m_Configuration({configuration}) {
        initialize();
    }

    Window::~Window() {
        if (m_Native) glfwDestroyWindow(m_Native);
    }

    void Window::initialize() {
        glfwWindowHint(GLFW_DECORATED, m_Configuration.options >= Options::Decorated);
        glfwWindowHint(GLFW_RESIZABLE, m_Configuration.options >= Options::Resizable);
        glfwWindowHint(GLFW_VISIBLE, m_Configuration.options >= Options::Visible);
        glfwWindowHint(GLFW_FLOATING, m_Configuration.options >= Options::Floating);

        if (m_Configuration.options >= Window::Options::Subscreen) subscreen();
        if (m_Configuration.options >= Window::Options::Fullscreen) fullscreen();

        ANDROMEDA_CORE_ASSERT(m_Native != nullptr, "Window not created.");
        glfwSetWindowUserPointer(m_Native, & m_Configuration);

        callbacks();
    }

    void Window::update() {
        glfwPollEvents();
    }
    void Window::subscreen() {
        m_Native = glfwCreateWindow(m_Configuration.viewport.width, m_Configuration.viewport.height, m_Configuration.title.data(), nullptr, nullptr);
    }
    void Window::fullscreen() {

    }
    void Window::callbacks() {
        glfwSetWindowCloseCallback(m_Native, [](GLFWwindow * window) {
            auto & configuration = * (Window::Configuration *) glfwGetWindowUserPointer(window);
            Andromeda::System::Event::Window::Close event;
            configuration.callbacks->close.transmit(event);
        });
    }
} /* Andromeda::System::Linux::Graphics::Display */
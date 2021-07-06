#include "window.hpp"

#include "andromeda/core/system/event/type/window.hpp"

namespace Andromeda::System::Linux::Graphics::Display {
    Window::Window(Window::Configuration configuration) : m_Configuration({configuration}) {
        m_Native = glfwCreateWindow(m_Configuration.viewport.width, m_Configuration.viewport.height, m_Configuration.title.data(), nullptr, nullptr);
    }

    Window::~Window() {

    }

    void Window::update() {

    }

} /* Andromeda::System::Linux::Graphics::Display */
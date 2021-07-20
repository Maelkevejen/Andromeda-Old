#pragma once

#include "andromeda/core/system/graphics/display/window.hpp"

#include <GLFW/glfw3.h>

namespace Andromeda::System::Linux::Graphics::Display {
    class Window : public Andromeda::System::Graphics::Display::Window {
      public:
        Window(Window::Configuration configuration, Window::Callbacks * callbacks);
        ~Window() override;

        void update() override;

        Window::Configuration configuration() const override;

      public:
        bool pressed(Andromeda::System::Input::Code::Keyboard::Key key) const override;
        bool pressed(Andromeda::System::Input::Code::Keyboard::Mod mod) const override;
        bool pressed(Andromeda::System::Input::Code::Mouse::Button button) const override;
        Andromeda::System::Structure::Duo<double> mouse() const override;

      private:
        void initialize();

        void subscreen();
        void fullscreen();

        void callbacks();
      private:
        Window::Configuration m_Configuration;
        Window::Data m_Data;
        GLFWwindow * m_Native;
    };
} /* Andromeda::System::Linux::Graphics::Display */

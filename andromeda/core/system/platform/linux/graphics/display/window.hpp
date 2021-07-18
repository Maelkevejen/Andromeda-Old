#pragma once

#include "andromeda/core/system/graphics/display/window.hpp"

#include <GLFW/glfw3.h>

namespace Andromeda::System::Linux::Graphics::Display {
    class Window : public Andromeda::System::Graphics::Display::Window {
      public:
        Window(Window::Configuration configuration);
        ~Window() override;

        void update() override;

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
        GLFWwindow * m_Native;
    };
} /* Andromeda::System::Linux::Graphics::Display */

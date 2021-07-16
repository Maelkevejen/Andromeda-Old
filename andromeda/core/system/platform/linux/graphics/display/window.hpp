#pragma once

#include "andromeda/core/system/graphics/display/window.hpp"

#include <GLFW/glfw3.h>

#include <memory>

namespace Andromeda::System::Linux::Graphics::Display {
    class Window : public Andromeda::System::Graphics::Display::Window {
      public:
        Window(Window::Configuration configuration);
        ~Window() override;

        void update() override;
        void callbacks(Window::Callbacks & callbacks) override;

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
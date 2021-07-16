#pragma once

#include "andromeda/core/system/graphics/display/monitor.hpp"

#include <GLFW/glfw3.h>

namespace Andromeda::System::Linux::Graphics::Display {
    class Monitor : public Andromeda::System::Graphics::Display::Monitor {
      public:
        Monitor(Andromeda::System::Graphics::Display::Monitor::Configuration configuration, GLFWmonitor * monitor);

        void update() override;

      private:
        void callbacks();
      private:
        Andromeda::System::Graphics::Display::Monitor::Configuration m_Configuration;
        GLFWmonitor * m_Native;
    };
} /* Andromeda::System::Linux::Graphics */
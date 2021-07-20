#pragma once

#include "andromeda/core/system/graphics/display/monitor.hpp"

#include <GLFW/glfw3.h>

namespace Andromeda::System::Linux::Graphics::Display {
    class Monitor : public Andromeda::System::Graphics::Display::Monitor {
      public:
        Monitor(Andromeda::System::Graphics::Display::Monitor::Data data, GLFWmonitor * monitor);

        void update() override;

        Monitor::Configuration configuration() const override;

      private:
        void configure();
        void callbacks();

      private:
        Andromeda::System::Graphics::Display::Monitor::Configuration m_Configuration;
        Andromeda::System::Graphics::Display::Monitor::Data m_Data;
        GLFWmonitor * m_Native;
    };
} /* Andromeda::System::Linux::Graphics */
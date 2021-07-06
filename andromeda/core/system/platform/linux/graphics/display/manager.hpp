#pragma once

#include "andromeda/core/system/graphics/display/manager.hpp"

#include "monitor.hpp"
#include "window.hpp"

namespace Andromeda::System::Linux::Graphics::Display {
    class Manager : Andromeda::System::Graphics::Display::Manager {
      public:
        Manager();

        void initialize() override;
    };
} /* Andromeda::System::Graphics::Display */
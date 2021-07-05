#pragma once

#include "andromeda/core/system/graphics/display/window.hpp"

namespace Andromeda::System::Linux::Graphics {
    class Window : Andromeda::System::Graphics::Display::Window {
      public:
        void configure(Configuration configuration) override;
        void update() override;
    };
} /* Andromeda::System::Linux::Graphics::Display */
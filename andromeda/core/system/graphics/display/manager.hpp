#pragma once

#include "monitor.hpp"
#include "window.hpp"

namespace Andromeda::System::Graphics::Display {
    class Manager {
      public:
        virtual ~Manager() = default;

        virtual void initialize();
    };
} /* Andromeda::System::Graphics::Display */
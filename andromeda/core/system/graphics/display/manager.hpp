#pragma once

#include "monitor.hpp"
#include "window.hpp"

#include <memory>

namespace Andromeda::System::Graphics::Display {
    class Manager {
      public:
        virtual ~Manager() = default;

        virtual void initialize() = 0;
        virtual void update() = 0;

        virtual void create(Window::Configuration configuration) = 0;
        
        static std::unique_ptr<Manager> instantiate();
    };
} /* Andromeda::System::Graphics::Display */
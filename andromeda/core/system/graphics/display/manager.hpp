#pragma once

#include "monitor.hpp"
#include "window.hpp"

#include <memory>

namespace Andromeda::System::Graphics::Display {
    class Manager {
      public:
        struct Callbacks {
            Window::Callbacks * window;
            Monitor::Callbacks * monitor;
        };
        struct Configuration {
            Callbacks callbacks;
        };
      public:
        virtual ~Manager() = default;

        virtual void update() = 0;

        virtual void create(Window::Configuration configuration) = 0;

        static std::unique_ptr<Manager> instantiate(Manager::Configuration configuration);
    };
} /* Andromeda::System::Graphics::Display */
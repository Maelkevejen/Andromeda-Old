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

        virtual bool pressed(Andromeda::System::Input::Code::Keyboard::Key key) const = 0;
        virtual bool pressed(Andromeda::System::Input::Code::Keyboard::Mod mod) const = 0;
        virtual bool pressed(Andromeda::System::Input::Code::Mouse::Button button) const = 0;
        virtual Andromeda::System::Structure::Duo<double> mouse() const = 0;

        virtual void create(Window::Configuration configuration) = 0;

        static std::unique_ptr<Manager> instantiate(Manager::Configuration configuration);
    };
} /* Andromeda::System::Graphics::Display */
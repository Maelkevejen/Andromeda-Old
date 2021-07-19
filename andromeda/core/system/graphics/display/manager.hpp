#pragma once

#include "monitor.hpp"
#include "window.hpp"

#include "andromeda/core/system/event/type/instance.hpp"

#include <memory>

namespace Andromeda::System::Graphics::Display {
    class Manager {
      public:
        struct Callbacks {
            struct Display {
                Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Instance::Display::Update, Manager *> update;
                Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Instance::Display::Initialize, Manager *> initialize;
                Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Instance::Display::Interrupt, Manager *> interrupt;
                Andromeda::System::Event::Manager::Serial<Andromeda::System::Event::Instance::Display::Terminate, Manager *> terminate;
            };
            std::shared_ptr<Manager::Callbacks::Display> display = std::make_shared<Manager::Callbacks::Display>();
            std::shared_ptr<Window::Callbacks> window = std::make_shared<Window::Callbacks>();
            std::shared_ptr<Monitor::Callbacks> monitor = std::make_shared<Monitor::Callbacks>();
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
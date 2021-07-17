#pragma once

#include "andromeda/core/system/graphics/display/manager.hpp"

#include "monitor.hpp"
#include "window.hpp"

#include <memory>
namespace Andromeda::System::Linux::Graphics::Display {
    class Manager : public Andromeda::System::Graphics::Display::Manager {
      public:
        Manager(Andromeda::System::Graphics::Display::Manager::Configuration configuration);
        ~Manager() override;

        void initialize();

        void update() override;

        bool pressed(Andromeda::System::Input::Code::Keyboard::Key key) const override;
        bool pressed(Andromeda::System::Input::Code::Keyboard::Mod mod) const override;
        bool pressed(Andromeda::System::Input::Code::Mouse::Button button) const override;
        Andromeda::System::Structure::Duo<double> mouse() const override;

        void create(Andromeda::System::Graphics::Display::Window::Configuration configuration) override;

      private:
        Andromeda::System::Graphics::Display::Manager::Configuration m_Configuration;
      private:
        std::vector<std::unique_ptr<Andromeda::System::Graphics::Display::Monitor>> m_Monitors;
        std::vector<std::unique_ptr<Andromeda::System::Graphics::Display::Window>> m_Windows;
    };
} /* Andromeda::System::Graphics::Display */
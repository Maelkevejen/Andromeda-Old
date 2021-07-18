#pragma once

#include "monitor.hpp"
#include "window.hpp"

#include "andromeda/core/system/graphics/display/manager.hpp"

#include <memory>
#include <mutex>

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
        void callbacks();

      private:
        Andromeda::System::Graphics::Display::Manager::Configuration m_Configuration;
      private:
        std::mutex m_Monitor_Mutex;
        std::vector<std::unique_ptr<Andromeda::System::Graphics::Display::Monitor>> m_Monitors;
      private:
        std::mutex m_Windows_Mutex;
        std::vector<std::unique_ptr<Andromeda::System::Graphics::Display::Window>> m_Windows;
    };
} /* Andromeda::System::Graphics::Display */
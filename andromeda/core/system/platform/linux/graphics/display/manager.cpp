#include "manager.hpp"

#include "andromeda/core/system/log/log.hpp"

#include <GLFW/glfw3.h>

namespace Andromeda::System::Linux::Graphics::Display {
    Manager::Manager() {
        initialize();
    }
    Manager::~Manager() {
        glfwTerminate();
    }
    void Manager::initialize() {
        ANDROMEDA_CORE_ASSERT(glfwInit() == GLFW_TRUE, "Failed to initialize GLFW");
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        int count = 0;
        auto monitors = glfwGetMonitors(&count);
        for (int monitor = 0; monitor < count; monitor++) m_Monitors.push_back(std::make_unique<Andromeda::System::Linux::Graphics::Display::Monitor>(monitors[monitor]));
    }
    void Manager::update() {

    }
    void Manager::create(Andromeda::System::Graphics::Display::Window::Configuration configuration) {
        m_Windows.push_back(std::make_unique<Andromeda::System::Linux::Graphics::Display::Window>(configuration));
    }
} /* Andromeda::System::Graphics::Display */
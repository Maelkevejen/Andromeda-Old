#include "manager.hpp"

#include "andromeda/core/system/log/log.hpp"

#include <GLFW/glfw3.h>

namespace Andromeda::System::Linux::Graphics::Display {
    Manager::Manager() {
        ANDROMEDA_CORE_TRACE("Linux Display Manager.");
        initialize();
    }
    Manager::~Manager() {
        glfwTerminate();
    }
    void Manager::initialize() {
        [[ maybe_unused ]] auto glfw = glfwInit();
        ANDROMEDA_CORE_ASSERT_MESSAGE(glfw == GLFW_TRUE, "Failed to initialize GLFW, code: {0}.", glfw);
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        int count = 0;
        auto monitors = glfwGetMonitors(&count);
        for (int monitor = 0; monitor < count; monitor++) m_Monitors.push_back(std::make_unique<Andromeda::System::Linux::Graphics::Display::Monitor>(monitors[monitor]));
        ANDROMEDA_CORE_INFO("Initialzed {0} monitors.", m_Monitors.size());
    }
    void Manager::update() {
        ANDROMEDA_CORE_TRACE("Updating Linux Display Manager.");
    }
    void Manager::create(Andromeda::System::Graphics::Display::Window::Configuration configuration) {
        ANDROMEDA_CORE_TRACE("Creating a Linux Display Manager.");
        m_Windows.push_back(std::make_unique<Andromeda::System::Linux::Graphics::Display::Window>(configuration));
    }
} /* Andromeda::System::Graphics::Display */

namespace Andromeda::System::Graphics::Display {
    std::unique_ptr<Manager> Manager::instantiate() {
        return std::make_unique<Andromeda::System::Linux::Graphics::Display::Manager>();
    }
} /* Andromeda::System::Graphics::Display */
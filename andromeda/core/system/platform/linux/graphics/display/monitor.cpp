#include "monitor.hpp"

namespace Andromeda::System::Linux::Graphics::Display {
    Monitor::Monitor(Andromeda::System::Graphics::Display::Monitor::Configuration configuration, GLFWmonitor * monitor) : m_Configuration(configuration), m_Native(monitor) {
        glfwSetMonitorUserPointer(m_Native, & m_Configuration);
        update();
        callbacks();
    }
    void Monitor::update() {
        m_Configuration.title = std::string(glfwGetMonitorName(m_Native));
        glfwGetMonitorPos(m_Native, & m_Configuration.position.x, & m_Configuration.position.y);
        glfwGetMonitorWorkarea(m_Native, & m_Configuration.area.x, & m_Configuration.area.y, & m_Configuration.area.width, & m_Configuration.area.height);
        const auto * mode = glfwGetVideoMode(m_Native);
        m_Configuration.mode = {
            .red = mode->redBits,
            .green = mode->greenBits,
            .blue = mode->blueBits,
            .frequency = mode->refreshRate,
            .width = mode->width,
            .height = mode->height,
        };
    }

    void Monitor::callbacks() {
        glfwSetMonitorCallback([](GLFWmonitor * monitor, int event) {
            auto configuration = static_cast<Monitor::Configuration *>(glfwGetMonitorUserPointer(monitor));
            switch (event) {
                case GLFW_CONNECTED: {
                    Andromeda::System::Event::Monitor::Connect event;
                    configuration->callbacks->connect.transmit(event);
                    break;
                }
                case GLFW_DISCONNECTED: {
                    Andromeda::System::Event::Monitor::Disconnect event;
                    configuration->callbacks->disconnect.transmit(event);
                    break;
                }
                default : {
                    break;
                }
            }
        });
    }

} /* Andromeda::System::Linux::Graphics::Display */


#include "monitor.hpp"

namespace Andromeda::System::Linux::Graphics::Display {
    Monitor::Monitor(GLFWmonitor * monitor) {
        m_Native = monitor;
        glfwSetMonitorUserPointer(m_Native, & m_Configuration);
        update();
    }
    Monitor::~Monitor() {

    }

    void Monitor::update() {
        m_Configuration.title = std::string(glfwGetMonitorName(m_Native));
        glfwGetMonitorPos(m_Native, & m_Configuration.position.x, & m_Configuration.position.y);
        glfwGetMonitorWorkarea(m_Native, & m_Configuration.area.x, & m_Configuration.area.y, & m_Configuration.area.width, & m_Configuration.area.height);
        const GLFWvidmode * mode = glfwGetVideoMode(m_Native);
        m_Configuration.mode = {
            .red = mode->redBits,
            .green = mode->greenBits,
            .blue = mode->blueBits,
            .frequency = mode->refreshRate,
            .width = mode->width,
            .height = mode->height,
        };
    }

} /* Andromeda::System::Linux::Graphics::Display */


#include "monitor.hpp"

#include "andromeda/core/system/log/log.hpp"

namespace Andromeda::System::Linux::Graphics::Display {
    Monitor::Monitor(Andromeda::System::Graphics::Display::Monitor::Data data, GLFWmonitor * monitor) : m_Data(data), m_Native(monitor) {
        ANDROMEDA_CORE_INFO("Obtaining Monitor.");
        configure();
    }

    void Monitor::update() {

    }

    Monitor::Configuration Monitor::configuration() const {
        return m_Configuration;
    }

    void Monitor::configure() {
        m_Configuration.title = std::string(glfwGetMonitorName(m_Native));
        glfwGetMonitorPos(m_Native, & m_Configuration.position.x, & m_Configuration.position.y);
        glfwGetMonitorWorkarea(m_Native, & m_Configuration.area.x, & m_Configuration.area.y, & m_Configuration.area.width, & m_Configuration.area.height);
        const auto mode = glfwGetVideoMode(m_Native);
        m_Configuration.mode = {
            .red = mode->redBits,
            .green = mode->greenBits,
            .blue = mode->blueBits,
            .frequency = mode->refreshRate,
            .width = mode->width,
            .height = mode->height,
        };
        ANDROMEDA_CORE_WARN("Stored Monitor {0}'s *this* pointer in configuration state.", m_Configuration.title);
        m_Data.monitor = this;
        glfwSetMonitorUserPointer(m_Native, & m_Data);

        callbacks();

        ANDROMEDA_CORE_INFO("Obtained Monitor {0} @ [{1}, {2}] with Area [ position: ({3}, {4}), dimensions: ({5}, {6}) ] and Mode [ rgb: ({7}, {8}, {9}), frequency: {10}, dimensions ({11}, {12})].", m_Configuration.title, m_Configuration.position.x, m_Configuration.position.y, m_Configuration.area.x, m_Configuration.area.y, m_Configuration.area.width, m_Configuration.area.height, m_Configuration.mode.red, m_Configuration.mode.green, m_Configuration.mode.blue, m_Configuration.mode.frequency, m_Configuration.mode.width, m_Configuration.mode.height);
    }

    void Monitor::callbacks() {
        ANDROMEDA_CORE_INFO("Setting Monitor {0} callbacks.", m_Configuration.title);
        glfwSetMonitorCallback([](GLFWmonitor * native, int event) {
            auto data = static_cast<Monitor::Data *>(glfwGetMonitorUserPointer(native));

            switch (event) {
                case GLFW_CONNECTED: {
                    Andromeda::System::Event::Monitor::Connect event;
                    data->callbacks->connect.transmit(event, data->monitor);
                    ANDROMEDA_CORE_TRACE("Connected Monitor {0}.", data->monitor->configuration().title);
                    break;
                }
                case GLFW_DISCONNECTED: {
                    Andromeda::System::Event::Monitor::Disconnect event;
                    data->callbacks->disconnect.transmit(event, data->monitor);
                    ANDROMEDA_CORE_TRACE("Disconnected Monitor {0}.", data->monitor->configuration().title);
                    break;
                }
            }
        });
    }

} /* Andromeda::System::Linux::Graphics::Display */

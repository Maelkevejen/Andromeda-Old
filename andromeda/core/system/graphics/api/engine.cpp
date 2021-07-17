#include "engine.hpp"

#include "andromeda/core/system/platform/graphics/vulkan/api/engine.hpp"
#include "andromeda/core/system/log/log.hpp"


namespace Andromeda::System::Graphics {
    std::unique_ptr<Engine> Engine::instantiate(Engine::Configuration configuration) {
        switch (configuration.type) {
            case Type::None : {
                ANDROMEDA_CORE_ERROR("Software Rendering is unsupported.");
                return nullptr;
            }
            case Type::Vulkan : {
                ANDROMEDA_CORE_WARN("Vulkan Rendering is experimental.");
                return std::make_unique<Andromeda::System::Graphics::Vulkan::Engine>();
            }
            ANDROMEDA_CORE_ERROR("Undefined Graphics API.");
            return nullptr;
        }
    }
} /* Andromeda::System::Graphics */
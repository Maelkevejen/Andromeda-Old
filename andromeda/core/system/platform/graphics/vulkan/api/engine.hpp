#pragma once

#include "andromeda/core/system/graphics/api/engine.hpp"
#include "andromeda/core/system/graphics/renderer/context.hpp"

#include <vector>
#include <memory>

namespace Andromeda::System::Graphics::Vulkan {
    class Engine : public Andromeda::System::Graphics::Engine {
      public:
        Engine() {

        }

        void initialize() override {

        }
      private:
        std::vector<std::unique_ptr<Andromeda::System::Graphics::Renderer::Context>> m_Contexts;
    };
} /* Andromeda::System::Graphics::Vulkan */
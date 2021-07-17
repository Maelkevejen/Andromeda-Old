#pragma once

#include <memory>

namespace Andromeda::System::Graphics::Renderer {
    class Context {
      public:
        virtual ~Context() = default;

        static std::unique_ptr<Context> instantiate(Andromeda::System::Graphics::Engine::Type type);
    };
} /* Andromeda::System::Graphics::Engine */
#include "andromeda/core/system/platform/linux/graphics/display/manager.hpp"

namespace Andromeda::System::Graphics::Display {
    std::unique_ptr<Andromeda::System::Graphics::Display::Manager> Manager::instantiate() {
        return std::make_unique<Andromeda::System::Linux::Graphics::Display::Manager>();
    }
} /* Andromeda::System::Graphics::Display */
#pragma once

#include <memory>

#include "andromeda/core/core.hpp"
#include "andromeda/core/instance.hpp"
#include "andromeda/core/system/log/log.hpp"

extern std::unique_ptr<Andromeda::Instance> Andromeda::instantiate();

int main(int, const char *[]) {
    auto instance = Andromeda::instantiate();
    Andromeda::System::Log::initialize({instance->configuration().log});

    ANDROMEDA_CORE_TRACE("[ Initialized / Andromeda ]");
    ANDROMEDA_CORE_INFO("[ Instantiating / Andromeda / {0} ... ]", instance->configuration().meta.name);

    instance->initialize();

    ANDROMEDA_CORE_INFO("[ Terminating / Andromeda / {0} ... ]", instance->configuration().meta.name);
    ANDROMEDA_CORE_TRACE("[ Status: {0} ]", instance->state().status);

    return instance->code();
}
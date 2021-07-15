#pragma once

#include <memory>

#include "andromeda/core/core.hpp"
#include "andromeda/core/instance.hpp"
#include "andromeda/core/system/log/log.hpp"

int main(int, const char *[]) {
    auto instance = Andromeda::Instance::instantiate();
    
    Andromeda::System::Log::initialize({instance->configuration().log});
    ANDROMEDA_CORE_INFO("[ Initialized / Andromeda // Logging ]");
    
    ANDROMEDA_CORE_TRACE("[ Initialized / Andromeda ]");
    ANDROMEDA_CORE_INFO("[ Initializing / Andromeda // {0} ]", instance->configuration().meta.name);

    instance->initialize();

    ANDROMEDA_CORE_INFO("[ Initialized / Andromeda // {0} ]", instance->configuration().meta.name);

    ANDROMEDA_INFO("[ Executing / Andromeda // {0} ] ", instance->configuration().meta.name);
    
    instance->execute();

    ANDROMEDA_CORE_INFO("[ Terminating / Andromeda / {0} ... ]", instance->configuration().meta.name);
    ANDROMEDA_CORE_TRACE("[ Status: {0} ]", instance->state().status);

    ANDROMEDA_CORE_INFO("[ Terminating / Andromeda // Logging ]");
    Andromeda::System::Log::shutdown();
    
    return instance->code();
}
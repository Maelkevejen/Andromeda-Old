#pragma once

namespace Andromeda::System::Structure::Status {
    enum class Runtime {
        Initialized = 0,
        Activated,
        Interrupted,
        Terminated,
        Nullified,
    };
    enum class Error {
        Undefined = 0,
        None,
    };
} /* Andromeda::System::Structure::Status */
#pragma once

namespace Andromeda::System::Structure::Status {
    enum class Runtime {
        Initialized,
        Activated,
        Interrupted,
        Terminated,
        Nullified,
    };
    enum class Error {
        Undefined,
    };
} /* Andromeda::System::Structure::Status */
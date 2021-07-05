#include "andromeda/core/instance.hpp"

#include "gtest/gtest.h"

class Basic : public Andromeda::Instance {
  public:
    Basic(Andromeda::Instance::Configuration configuration) :
        m_Configuration(configuration),
        m_State({
        .status = Andromeda::System::Structure::Status::Runtime::Nullified
    }) {
        m_State.status = Andromeda::System::Structure::Status::Runtime::Nullified;
    }

    ~Basic() override {

    }

    void initialize() override {
        m_State.status = Andromeda::System::Structure::Status::Runtime::Initialized;
    }

    void execute() override {
        m_State.status = Andromeda::System::Structure::Status::Runtime::Activated;
    }

    void interrupt() override {
        m_State.status = Andromeda::System::Structure::Status::Runtime::Interrupted;
    }

    void terminate() override {
        m_State.status = Andromeda::System::Structure::Status::Runtime::Terminated;
    }

    const Instance::Configuration & configuration() const override {
        return m_Configuration;
    }
    const Instance::State & state() const override {
        return m_State;
    }

    int code() const override {
        switch (m_State.error) {
            case Andromeda::System::Structure::Status::Error::Undefined :
                return 0;
            default:
                return 0;
        }
    }
  private:
    Andromeda::Instance::Configuration m_Configuration;
    Andromeda::Instance::State m_State;
};

std::unique_ptr<Andromeda::Instance> Andromeda::instantiate() {
    return std::make_unique<Basic>(
    Andromeda::Instance::Configuration {
        .meta = {
            .name = "Test Instance",
            .engine = Andromeda::Titles::engine,
        },
        .log = {
            .name = "test",
            .log_directory = "logging/test.log",
            .max_log_files = 3,
            .max_log_file_size = 5 * 1024 * 1024,
            .threads = 8096,
            .workers = 1,
        },
    });
}

TEST(Instance, Execute) {
    EXPECT_NO_THROW({
        auto instance = Andromeda::instantiate();
        Andromeda::System::Log::initialize({instance->configuration().log});

        ANDROMEDA_CORE_TRACE("[ Initializing / Andromeda ]");
        ANDROMEDA_CORE_INFO("[ Instantiating / Andromeda / {0} ... ]", instance->configuration().meta.name);

        EXPECT_EQ(instance->state().status, Andromeda::System::Structure::Status::Runtime::Nullified);

        instance->initialize();

        EXPECT_EQ(instance->state().status, Andromeda::System::Structure::Status::Runtime::Initialized);

        instance->execute();

        EXPECT_EQ(instance->state().status, Andromeda::System::Structure::Status::Runtime::Activated);

        instance->terminate();

        ANDROMEDA_CORE_INFO("[ Terminating / Andromeda / {0} ... ]", instance->configuration().meta.name);
        ANDROMEDA_CORE_TRACE("[ {1}: Status: {0} ]", instance->state().status, (instance->state().status == Andromeda::System::Structure::Status::Runtime::Activated ? "Active" : "Inactive"));

        Andromeda::System::Log::shutdown();
        EXPECT_EQ(instance->state().status, Andromeda::System::Structure::Status::Runtime::Terminated);
    });
}

TEST(Instance, Interrupt) {
    EXPECT_NO_THROW({
        auto instance = Andromeda::instantiate();
        Andromeda::System::Log::initialize({instance->configuration().log});

        ANDROMEDA_CORE_TRACE("[ Initializing / Andromeda ]");
        ANDROMEDA_CORE_INFO("[ Instantiating / Andromeda / {0} ... ]", instance->configuration().meta.name);

        EXPECT_EQ(instance->state().status, Andromeda::System::Structure::Status::Runtime::Nullified);

        instance->initialize();

        EXPECT_EQ(instance->state().status, Andromeda::System::Structure::Status::Runtime::Initialized);

        instance->execute();

        EXPECT_EQ(instance->state().status, Andromeda::System::Structure::Status::Runtime::Activated);

        instance->interrupt();

        EXPECT_EQ(instance->state().status, Andromeda::System::Structure::Status::Runtime::Interrupted);

        instance->terminate();

        ANDROMEDA_CORE_INFO("[ Terminating / Andromeda / {0} ... ]", instance->configuration().meta.name);
        ANDROMEDA_CORE_TRACE("[ {1}: Status: {0} ]", instance->state().status, (instance->state().status == Andromeda::System::Structure::Status::Runtime::Activated ? "Active" : "Inactive"));

        Andromeda::System::Log::shutdown();
        EXPECT_EQ(instance->state().status, Andromeda::System::Structure::Status::Runtime::Terminated);
    });
}

TEST(Instance, Choppy) {
    EXPECT_NO_THROW({
        auto instance = Andromeda::instantiate();
        Andromeda::System::Log::initialize({instance->configuration().log});

        ANDROMEDA_CORE_TRACE("[ Initializing / Andromeda ]");
        ANDROMEDA_CORE_INFO("[ Instantiating / Andromeda / {0} ... ]", instance->configuration().meta.name);

        EXPECT_EQ(instance->state().status, Andromeda::System::Structure::Status::Runtime::Nullified);

        instance->initialize();

        EXPECT_EQ(instance->state().status, Andromeda::System::Structure::Status::Runtime::Initialized);

        instance->execute();

        EXPECT_EQ(instance->state().status, Andromeda::System::Structure::Status::Runtime::Activated);

        instance->interrupt();

        EXPECT_EQ(instance->state().status, Andromeda::System::Structure::Status::Runtime::Interrupted);

        instance->execute();

        EXPECT_EQ(instance->state().status, Andromeda::System::Structure::Status::Runtime::Activated);

        instance->terminate();

        ANDROMEDA_CORE_INFO("[ Terminating / Andromeda / {0} ... ]", instance->configuration().meta.name);
        ANDROMEDA_CORE_TRACE("[ {1}: Status: {0} ]", instance->state().status, (instance->state().status == Andromeda::System::Structure::Status::Runtime::Activated ? "Active" : "Inactive"));

        Andromeda::System::Log::shutdown();
        EXPECT_EQ(instance->state().status, Andromeda::System::Structure::Status::Runtime::Terminated);
    });
}
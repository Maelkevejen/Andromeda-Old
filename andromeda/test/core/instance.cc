#include "gtest/gtest.h"

#include "andromeda/core/instance.hpp"

class Test : public Andromeda::Instance {
  public:
    Test(Andromeda::Instance::Configuration configuration) : m_Configuration(configuration), m_State({.status = 1, .active = false}) {

    }
    ~Test() override {}
    void initialize() override {
        m_State.status = 0;
    }
    const Instance::Configuration & configuration() const override {
        return m_Configuration;
    }
    const Instance::State & state() const override {
        return m_State;
    }
  private:
    Andromeda::Instance::Configuration m_Configuration;
    Andromeda::Instance::State m_State;
};

std::unique_ptr<Andromeda::Instance> Andromeda::instantiate() {
    return std::make_unique<Test>(Andromeda::Instance::Configuration {
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
        }
    });
}

TEST(Instance, Create) {
    EXPECT_NO_THROW({
        auto instance = Andromeda::instantiate();
        Andromeda::Logging::Log::initialize({instance->configuration().log});

        ANDROMEDA_CORE_TRACE("[ Initialized / Andromeda ]");
        ANDROMEDA_CORE_INFO("[ Instantiating / Andromeda / {0} ... ]", instance->configuration().meta.name);

        instance->initialize();

        ANDROMEDA_CORE_INFO("[ Terminating / Andromeda / {0} ... ]", instance->configuration().meta.name);
        ANDROMEDA_CORE_TRACE("[ {1}: Status: {0} ]", instance->state().status, (instance->state().active ? "Active" : "Inactive"));
        EXPECT_EQ(instance->state().status, 0);
    });
}
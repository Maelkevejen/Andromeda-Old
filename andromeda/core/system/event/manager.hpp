#pragma once

#include "event.hpp"
#include "andromeda/core/system/event/type/monitor.hpp"
#include "andromeda/core/system/event/type/mouse.hpp"
#include "andromeda/core/system/event/type/window.hpp"

#include <algorithm>
#include <execution>

namespace Andromeda::System::Event {
    template <class Event>
    class Manager {
      public:
        void subscribe(Andromeda::Structure::Callback<Event &> callback) {
            m_Callbacks.push_back(callback);
        }
        void unsubscribe(Andromeda::Structure::Callback<Event &> callback) {
            m_Callbacks.erase(std::remove(std::execution::par_unseq, std::begin(m_Callbacks), std::end(m_Callbacks), callback));
        }
        void update(Event & event) {
            m_Event = event;
        }
        void series() {
            std::for_each(std::begin(m_Callbacks), std::end(m_Callbacks), [&](const auto callback) {
                callback(m_Event);
            });
        }
      private:
        std::vector<Andromeda::Structure::Callback<Event &>> m_Callbacks;
        Event m_Event;
    };
} /* Andromeda::System::Event */
#pragma once

#include "andromeda/core/core.hpp"

#include <algorithm>
#include <execution>
#include <vector>

namespace Andromeda::System::Event::Manager {

    template <class Event>
    class Serial {
      private:
        using Callback = Andromeda::Structure::Callback<Event &>;
      public:
        void listen(Callback callback) {
            m_Callbacks.push_back(callback);
        }
        void deafen(Callback callback) {
            m_Callbacks.erase(std::remove_if(std::execution::par_unseq, std::begin(m_Callbacks), std::end(m_Callbacks), [&callback](const Callback & other) {
                return callback.template target<Callback>() == other.template target<Callback>();
            }));
        }
        void transmit(Event & event) {
            std::for_each(std::execution::par_unseq, std::begin(m_Callbacks), std::end(m_Callbacks), [&](const Callback & callback) {
                callback(event);
            });
            event.status = Andromeda::System::Structure::Status::Event::Used;
        }
      private:
        std::vector<Callback> m_Callbacks;
    };

    template <class Event>
    class Parallel {
      private:
        using Callback = Andromeda::Structure::Callback<Event &>;
      public:
        void listen(Callback callback) {
            m_Callbacks.push_back(callback);
        }
        void deafen(Callback callback) {
            m_Callbacks.erase(std::remove_if(std::execution::par_unseq, std::begin(m_Callbacks), std::end(m_Callbacks), [&callback](const Callback & other) {
                return callback.template target<Callback>() == other.template target<Callback>();
            }));
        }
        void queue(Event & event) {
            m_Events.push_back(event);
        }
        void deque() {
            m_Events.pop_back();
        }
        void clear() {
            m_Events.clear();
        }
        void transmit() {
            std::for_each(std::execution::par_unseq, std::begin(m_Callbacks), std::end(m_Callbacks), [&](const Callback & callback) {
                std::for_each(std::execution::seq, std::begin(m_Events), std::end(m_Events), [&](Event & event) {
                    callback(event);
                });
            });
        }
        void parallel() {
            std::for_each(std::execution::par_unseq, std::begin(m_Callbacks), std::end(m_Callbacks), [&](const Callback & callback) {
                std::for_each(std::execution::par, std::begin(m_Events), std::end(m_Events), [&](Event & event) {
                    callback(event);
                });
            });
        }
        void latest() {
            std::for_each(std::execution::par_unseq, std::begin(m_Callbacks), std::end(m_Callbacks), [&](const Callback & callback) {
                callback(m_Events.back());
            });
        }
      private:
        std::vector<Callback> m_Callbacks;
        std::vector<Event> m_Events;
    };
} /* Andromeda::System::Event */
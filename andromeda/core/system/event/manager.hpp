#pragma once

#include "andromeda/core/core.hpp"

#include <algorithm>
#include <execution>
#include <vector>

namespace Andromeda::System::Event::Manager {

    template <class Event, class ... Arguments>
    class Serial {
      private:
        using Callback = Andromeda::Structure::Callback<Event, Arguments ...>;
      public:
        void listen(Callback callback) {
            m_Callbacks.push_back(callback);
        }
        void await(Callback callback) {
            m_Awaiters.push_back(callback);
        }
        void deafen(Callback callback) {
            m_Callbacks.erase(std::remove_if(std::execution::par_unseq, std::begin(m_Callbacks), std::end(m_Callbacks), [& callback](const Callback & other) {
                return callback.template target<Callback>() == other.template target<Callback>();
            }));
        }
        void transmit(Event event, Arguments ... arguments) {
            std::for_each(std::execution::par_unseq, std::begin(m_Callbacks), std::end(m_Callbacks), [event = std::forward<Event>(event), ... arguments = std::forward<Arguments>(arguments)](const Callback & callback) {
                callback(event, arguments ...);
            });
            std::for_each(std::execution::par_unseq, std::begin(m_Awaiters), std::end(m_Awaiters), [event = std::forward<Event>(event), ... arguments = std::forward<Arguments>(arguments)](const Callback & callback) {
                callback(event, arguments ...);
            });
            m_Awaiters.clear();
        }
      private:
        std::vector<Callback> m_Callbacks;
        std::vector<Callback> m_Awaiters;
    };

    template <class Event, class ... Arguments>
    class Parallel {
      private:
        using Callback = Andromeda::Structure::Callback<Event, Arguments ...>;
      public:
        void listen(Callback callback) {
            m_Callbacks.push_back(callback);
        }
        void deafen(Callback callback) {
            m_Callbacks.erase(std::remove_if(std::execution::par_unseq, std::begin(m_Callbacks), std::end(m_Callbacks), [& callback](const Callback & other) {
                return callback.template target<Callback>() == other.template target<Callback>();
            }));
        }
        void queue(Event event) {
            m_Events.push_back(event);
        }
        void deque() {
            m_Events.pop_back();
        }
        void clear() {
            m_Events.clear();
        }
        void transmit(Arguments ... arguments) {
            std::for_each(std::execution::par_unseq, std::begin(m_Callbacks), std::end(m_Callbacks), [&](const Callback & callback) {
                std::for_each(std::execution::seq, std::begin(m_Events), std::end(m_Events), [callback, ... arguments = std::forward<Arguments>(arguments)](Event event) {
                    callback(event, arguments ...);
                });
            });
        }
        void parallel(Arguments ... arguments) {
            std::for_each(std::execution::par_unseq, std::begin(m_Callbacks), std::end(m_Callbacks), [&](const Callback & callback) {
                std::for_each(std::execution::par_unseq, std::begin(m_Events), std::end(m_Events), [callback, ... arguments = std::forward<Arguments>(arguments)](Event event) {
                    callback(event, arguments ...);
                });
            });
        }
        void latest(Arguments ... arguments) {
            auto back = m_Events.back();
            std::for_each(std::execution::par_unseq, std::begin(m_Callbacks), std::end(m_Callbacks), [ &, back = std::forward<Event>(back), ... arguments = std::forward<Arguments>(arguments)](const Callback & callback) {
                callback(back, arguments ...);
            });
            deque();
        }
      private:
        std::vector<Callback> m_Callbacks;
        std::vector<Event> m_Events;
    };
} /* Andromeda::System::Event */
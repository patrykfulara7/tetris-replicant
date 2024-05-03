#pragma once

#include "ampch.hxx"

namespace Automata {
    enum class EventType {
        None = 0,
        KeyPressed,
        KeyReleased,
    };

    class Event {
      public:
        virtual ~Event() = default;
        virtual EventType GetEventType() const = 0;
    };
} // namespace Automata

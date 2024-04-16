#pragma once

#include "ampch.hxx"

#include "Core/KeyCodes.hxx"

#include "Events/Event.hxx"

namespace Automata
{
    class KeyEvent : public Event
	{
	protected:
		KeyEvent(KeyCode keycode) :
			m_keyCode(keycode)
		{
		}

		KeyCode m_keyCode;

	public:
		inline KeyCode GetKeyCode(void) const { return m_keyCode; }
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(KeyCode keycode) :
			KeyEvent(keycode)
		{
		}

        EventType GetEventType() const override { return EventType::KeyPressed; }
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(KeyCode keycode) :
			KeyEvent(keycode)
		{
		}

        EventType GetEventType() const override { return EventType::KeyReleased; }
	};
}

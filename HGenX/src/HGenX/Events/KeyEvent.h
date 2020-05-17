#pragma once

#include "HGenX/Events/Event.h"


namespace HGenx
{
	class HGenX_API KeyEvent: public Event
	{
	public:
		int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode):m_KeyCode{keycode} {}

		int m_KeyCode;
	};

	class HGenX_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatcount) : KeyEvent{keycode}, m_RepeatCount{repeatcount} {}

		int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int m_RepeatCount;
	};

	class HGenX_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode) : KeyEvent{keycode} {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent : " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)								// added ENUM_CLASS_TYPE to hint files by mistake; 
	};

	class HGenX_API KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(int keycode) : KeyEvent{ keycode } {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent : " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};

} // end of namespace HGenx






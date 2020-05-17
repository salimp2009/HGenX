#pragma once

#include "HGenX/Events/Event.h"



namespace HGenx {
	class HGenX_API WindowResizeEvent :public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned height) : m_Width{width}, m_Height{height} {}

		unsigned int GetWidth()  const { return m_Width; }
		unsigned int GetHeight() const { return m_Height; }

		std::string ToString() const override 
		{
			std::stringstream ss;
			ss << " WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int m_Width, m_Height;
	};

	class HGenX_API WindowCloseEvent :public Event
	{
	public:
		WindowCloseEvent() = default;

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class HGenX_API AppTickEvent :public Event
	{
	public:
		AppTickEvent() = default;

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class HGenX_API AppUpdateEvent :public Event
	{
	public:
		AppUpdateEvent() = default;

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class HGenX_API AppRenderEvent :public Event
	{
	public:
		AppRenderEvent() = default;

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	

} // end of namespace HGenx
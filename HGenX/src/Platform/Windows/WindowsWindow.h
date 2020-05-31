#pragma once

#include "HGenX/Window.h"
#include <GLFW/glfw3.h>

namespace HGenx
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		unsigned int GetWidth()  const override { return m_Data.Width;}
		unsigned int GetHeight() const override { return m_Data.Height; }

		// Window Attributes
		void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback;}
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		//virtual void* GetNativeWindow() const { return m_Window; } // included in current code but not in video yet

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width{0}, Height{0};
			bool VSync{};

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};


} // end of namespace HGenx



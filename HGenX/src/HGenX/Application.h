#pragma once
#include "Core.h"
#include "Log.h"
#include "Events/Event.h"
#include "HGenX/Events/ApplicationEvent.h"
#include "Window.h"


namespace HGenx {

	class HGenX_API Application
	{
	public:

		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running{ true };
	};

	// To be defined in Client
	Application* CreateApplication();
}



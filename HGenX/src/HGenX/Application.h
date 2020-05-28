#pragma once
#include "Core.h"
#include "Log.h"
#include "Events/Event.h"
#include "Window.h"


namespace HGenx {

	class HGenX_API Application
	{
	public:

		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running{ true };
	};

	// To be defined in Client
	Application* CreateApplication();
}



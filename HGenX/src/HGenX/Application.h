#pragma once
#include "Core.h"

#include "HGenX/Window.h"
#include "HGenX/LayerStack.h"
#include "HGenX/Events/Event.h"
#include "HGenX/Events/ApplicationEvent.h"



namespace HGenx {

	class HGenX_API Application
	{
	public:

		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverLay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		
		std::unique_ptr<Window> m_Window;
		bool m_Running{ true };
		LayerStack m_LayerStack;
	};

	// To be defined in Client
	Application* CreateApplication();
}



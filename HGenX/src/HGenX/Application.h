#pragma once
#include "Core.h"

#include "HGenX/Window.h"
#include "HGenX/LayerStack.h"
#include "HGenX/Events/Event.h"
#include "HGenX/Events/ApplicationEvent.h"

#include "HGenX/ImGui/ImGuiLayer.h"



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

		static Application& Get() { return *s_Instance; }
		Window& GetWindow() { return *m_Window; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		ImGuiLayer* m_ImGuiLayer;						// Unique_ptr was used in video but revised to raw pointer !!
		std::unique_ptr<Window> m_Window;
		bool m_Running{ true };
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};

	// To be defined in Client
	Application* CreateApplication();
}



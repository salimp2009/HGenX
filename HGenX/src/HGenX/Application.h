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
		ImGuiLayer& GetImGui() { return *m_ImGuiLayer; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		ImGuiLayer* m_ImGuiLayer;					
		//std::unique_ptr<ImGuiLayer>m_ImGuiLayer;				// Alternative implemantantion by Salim	
		std::unique_ptr<Window> m_Window;
		bool m_Running{ true };
		LayerStack m_LayerStack;

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
	private:
		static Application* s_Instance;
	};

	// To be defined in Client
	Application* CreateApplication();
}



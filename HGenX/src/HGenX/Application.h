#pragma once
#include "Core.h"

#include "Window.h"
#include "HGenX/LayerStack.h"
#include "HGenX/Events/Event.h"
#include "HGenX/Events/ApplicationEvent.h"

#include "HGenX/ImGui/ImGuiLayer.h"
#include "HGenX/Renderer/Shader.h"
#include "HGenX/Renderer/Buffer.h"
#include "HGenX/Renderer/VertexArray.h"

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

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;					
		//std::unique_ptr<ImGuiLayer>m_ImGuiLayer;				// Alternative implemantantion by Salim	
		bool m_Running{ true };
		LayerStack m_LayerStack;

		//unsigned int m_VertexArray; // TODO: Delete
		std::shared_ptr<Shader>m_Shader;
		std::shared_ptr<VertexArray>m_VertexArray;
		std::shared_ptr<VertexBuffer>m_VertexBuffer;
		std::shared_ptr<IndexBuffer>m_IndexBuffer;
		
	private:
		static Application* s_Instance;
	};

	// To be defined in Client
	Application* CreateApplication();
}



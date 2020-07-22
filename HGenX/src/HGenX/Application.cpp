#include "hgpch.h"
#include "HGenx/Application.h"

#include "HGenX/Log.h"
#include "HGenX/Events/KeyEvent.h"
#include "HGenX/Events/MouseEvent.h"
#include "HGenX/Input.h"

#include <glad/glad.h>

namespace HGenx {

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		HG_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(HG_BIND_EVENT_FN(Application::OnEvent));

		m_ImGuiLayer = new ImGuiLayer();
		PushOverLay(m_ImGuiLayer);

		glGenVertexArrays(1, &m_VertexArray);
		glBindVertexArray(m_VertexArray);

		float vertices[3 * 3] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};

		m_VertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
		

		unsigned int indices[3] = { 0, 1, 2 };
		m_IndexBuffer.reset(IndexBuffer::Create(indices, sizeof(indices)/sizeof(uint32_t)));			 

		std::string vertexSrc = R"(
			#version 450 core

			layout(location=0) in vec3 a_Position;

			out vec3 v_Position;
				
			void main()
			{
				v_Position=a_Position;
				gl_Position=vec4(a_Position , 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 450 core

			layout(location=0) out vec4 color;

			in vec3 v_Position;
				
			void main()
			{
				color=vec4(v_Position*0.5 + 0.5, 1.0);
			}
		)";

		m_Shader.reset(new Shader(vertexSrc, fragmentSrc));

		// Alternative way using instead of raw pointer
		//m_ImGuiLayer = std::make_unique<ImGuiLayer>();
		//PushOverLay(m_ImGuiLayer.get());
	}
	

	Application::~Application() 
	{

	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}


	void Application::PushOverLay(Layer* layer)
	{
		m_LayerStack.PushOverLay(layer);
		layer->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(HG_BIND_EVENT_FN(Application::OnWindowClose));
		
		// Alternative to std::bind
		//auto f = [this](WindowCloseEvent& e) {  return OnWindowClose(e); };
		//dispatcher.Dispatch<WindowCloseEvent>(f);
		HG_CORE_TRACE("{0}", e);
		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
		{
			if (e.Handled)
				break;
			(*it)->OnEvent(e);
			
		}
	}

	void Application::Run()
	{
		while (m_Running)
		{
		
			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			m_Shader->Bind();
			glBindVertexArray(m_VertexArray);
			glDrawElements(GL_TRIANGLES, m_IndexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack)
				layer->OnImGuiRender();
			m_ImGuiLayer->End();

			m_Window->OnUpdate();
		}
	}

	// when the window is close the application is closed by changing m_Running to false
	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

} // end of namespace HGenx
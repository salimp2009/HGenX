#include "hgpch.h"
#include "Application.h"
#include "HGenX/Events/KeyEvent.h"
#include "HGenX/Events/MouseEvent.h"

#include <GLFW/glfw3.h>



namespace HGenx {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application() 
	{
		m_Window =std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}
	

	Application::~Application() 
	{

	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		HG_CORE_TRACE("{0}", e);
	}

	void Application::Run()
	{
	
		while (m_Running)
		{
			glClearColor(1.0f, 0.0f, 1.0, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
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
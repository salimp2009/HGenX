#include "hgpch.h"
#include "Application.h"
#include "HGenX/Events/ApplicationEvent.h"
#include "HGenX/Events/KeyEvent.h"
#include "HGenX/Events/MouseEvent.h"




namespace HGenx {

	Application::Application() 
	{
	}
	

	Application::~Application() 
	{
	}

	void Application::Run()
	{
		Log::GetCoreLogger()->set_level(spdlog::level::trace);
		Log::GetClientLogger()->set_level(spdlog::level::trace);

		WindowResizeEvent e(1280,720);
		KeyPressedEvent k(25, 5);
		MouseButtonPressedEvent m(45);


		if (e.IsInCategory(EventCategoryApplication) && k.IsInCategory(EventCategoryKeyboard) && m.IsInCategory(EventCategoryMouse))  
		{
			HG_TRACE(e);
			HG_TRACE(k);
			HG_TRACE(m);
		}

		if (e.IsInCategory(EventCategoryInput))
		{
			HG_TRACE(e);
			HG_TRACE(k);
			HG_TRACE(m);
		}
		
		while (true);
	}


}
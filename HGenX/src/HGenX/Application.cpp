#include "Application.h"
#include "HGenX/Events/ApplicationEvent.h"
#include "HGenX/Events/KeyEvent.h"


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
		//HG_TRACE(e);

		if (e.IsInCategory(EventCategoryApplication))
		{
			HG_TRACE(e);
		}

		if (e.IsInCategory(EventCategoryInput))
		{
			HG_TRACE(e);
		}
		
		while (true);
	}


}
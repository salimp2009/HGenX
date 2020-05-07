#pragma once
#include "Core.h"
#include "Log.h"
#include "Events/Event.h"


namespace HGenx {

	class HGenX_API Application
	{
	public:

		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in Client
	Application* CreateApplication();
}



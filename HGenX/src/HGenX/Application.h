#pragma once
#include "Core.h"


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



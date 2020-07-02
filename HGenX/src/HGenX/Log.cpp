#include "hgpch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

//

namespace HGenx {
	std::shared_ptr<spdlog::logger>Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger>Log::s_ClientLogger;

	void Log::Init() 
	{
		// it is a colored pattern; start color:%^  , [%T] for time stamped 
		// %n is name of logger (Client or Core) log number, %v the message, %$ is end of color range
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_CoreLogger = spdlog::stdout_color_mt("HGenx");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger=spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}

#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace HGenx {
	class HGenX_API Log
	{
		public:
			static void Init();

			inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
			inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// CORE Log Macros
#define HG_CORE_TRACE(...)	::HGenx::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HG_CORE_INFO(...)	::HGenx::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HG_CORE_WARN(...)	::HGenx::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HG_CORE_ERROR(...)	::HGenx::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HG_CORE_FATAL(...)	::HGenx::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Log Macros
#define HG_TRACE(...)		::HGenx::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HG_INFO(...)		::HGenx::Log::GetClientLogger()->info(__VA_ARGS__)
#define HG_WARN(...)		::HGenx::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HG_ERROR(...)		::HGenx::Log::GetClientLogger()->error(__VA_ARGS__)
#define HG_FATAL(...)		::HGenx::Log::GetClientLogger()->critical(__VA_ARGS__)




#pragma once



#ifdef HG_PLATFORM_WINDOWS
	#ifdef HG_BUILD_DLL
		#define HGenX_API __declspec(dllexport)
	#else
		#define HGenX_API __declspec(dllimport)
	#endif // HG_BUILD_DLL
#else
	#error HGenX only support Windows
#endif 


#ifdef HG_DEBUG
	#if defined(HG_PLATFORM_WINDOWS)
		#define HG_DEBUGBREAK() __debugbreak()
	#elif defined(HG_PLATFORM_LINUX)
		#include <signal.h>
		#define HG_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesnot support debugbreak yet!"
	#endif
	#define HG_ENABLE_ASSERTS
#else	
	#define HG_DEBUGBREAK()
#endif 


#ifdef HG_ENABLE_ASSERTS
	#define HG_ASSERT(x, ...) { if(!(x)) { HG_ERROR("Assertion Failed: {0}", __VA_ARGS__); HG_DEBUGBREAK();} }
	#define HG_CORE_ASSERT(x, ...) {if(!(x)){ HG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); HG_DEBUGBREAK();} }
#else
	#define HG_ASSERT(x, ...)
	#define HG_CORE_ASSERT(x, ...)
#endif

#define HG_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1) // TODO:: change to lambda included in the recent code ; differes from video
#define BIT(x) (1 << x)


	
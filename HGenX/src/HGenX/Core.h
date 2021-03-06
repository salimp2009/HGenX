#pragma once

#include <memory>


#ifdef HG_PLATFORM_WINDOWS
#if HG_DYNAMIC_LINK
	#ifdef HG_BUILD_DLL
		#define HGenX_API __declspec(dllexport)
	#else
		#define HGenX_API __declspec(dllimport)
	#endif 
#else
	#define HGenX_API
#endif
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

//#define HG_BIND_EVENT_FN(fn) [this](auto& x) {return fn(x);}			     // revised std::bind to lambda...1st version
//#define HG_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)   // Original version from youtube; DELETE THIS
//#define HG_BIND_EVENT_FN(fn) [this](auto&&... x) ->decltype(fn(std::forward<decltype(x)>(x)...)){return fn(std::forward<decltype(x)>(x)...);}  // TOCHECK; Salim version; works ok but gives intellisense error; in Application.cpp SetEventCallback(HG_BIND_EVENT_FN(Application::OnEvent));
#define HG_BIND_EVENT_FN(fn) [this](auto&&... x) ->decltype(auto){return fn(std::forward<decltype(x)>(x)...);}							   // hazel commit version
//#define HG_BIND_EVENT_FN(fn) [this](auto&&... x) {return fn(std::forward<decltype(x)>(x)...);}							  

#define BIT(x) (1 << x)


namespace HGenx {

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename... Args>
	constexpr Ref<T> CreateRef(Args&&... args)
	{
		return std:make_shared<T>(std::forward<Args>(args)...);
	}
}


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

#define BIT(x) (1 << x)

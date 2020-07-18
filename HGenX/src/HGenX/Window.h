#pragma once

#include "hgpch.h"

#include "HGenX/Core.h"
#include "HGenX/Events/Event.h"


namespace HGenx
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(std::string title = "HGenX Engine", unsigned int width=1280, unsigned height=720) :Title{ std::move(title) }, Width{ width }, Height{ height } {}
	};

	// Interface representing a desktop system based Window
	class HGenX_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;
		
		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth()  const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window Attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const		= 0;
		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
		//static std::unique_ptr<Window> Create(const WindowProps& props = WindowProps());  // will be refactored later with using Scope=std::unique_ptr<T>
	};







} 

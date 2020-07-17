#pragma once

#include "HGenX/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace HGenx {

	class OpenGLContext:public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	
		virtual ~OpenGLContext() = default;
	private:
		GLFWwindow* m_WindowHandle;
	};

}

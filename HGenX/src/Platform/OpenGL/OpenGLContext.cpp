#include "hgpch.h"
#include "OpenGLContext.h" 

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace HGenx {
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle): m_WindowHandle{windowHandle}
	{
		HG_CORE_ASSERT(windowHandle, "Window Handle is null");
	}
	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		HG_CORE_ASSERT(status, "Could not initialize GLFW!");

		HG_CORE_INFO("OpenGL GPU INFO:");  // GPU Vender and model info 
		HG_CORE_INFO("	Vendor: {0}", glGetString(GL_VENDOR));
		HG_CORE_INFO("	Renderer: {0}", glGetString(GL_RENDERER));
		HG_CORE_INFO("	Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}
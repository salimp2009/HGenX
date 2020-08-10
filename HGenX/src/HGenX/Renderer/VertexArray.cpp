#include "hgpch.h"

#include "HGenX/Renderer/VertexArray.h"
#include "HGenX/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace HGenx {

	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None:		HG_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
		case RendererAPI::OpenGL:	return new OpenGLVertexArray();
		//case RendererAPI::OpenGL:	return CreateRef<OpenGLVertexArray>();  // NOTE: if used change the return type Ref<VertexArray>
		}

		HG_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}


}
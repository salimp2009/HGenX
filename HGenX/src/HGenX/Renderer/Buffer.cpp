#include "hgpch.h"
#include "HGenX/Renderer/Buffer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"
#include "HGenX/Renderer/Renderer.h"

namespace HGenx {

	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None:		HG_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
			case RendererAPI::OpenGL:	return new OpenGLVertexBuffer(vertices, size);	
		}
		
		HG_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None:		HG_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
			case RendererAPI::OpenGL:	return new OpenGLIndexBuffer(indices, size);
		}

		HG_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}


	//TODO: Change above to Ref<> (shared pointer)

	//Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
	//{
	//	switch (Renderer::GetAPI())
	//	{
	//		case RendererAPI::None:		HG_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
	//		case RendererAPI::OpenGL:	return CreateRef<OpenGLVertexBuffer>(vertices, size);
	//	}
	//	HG_CORE_ASSERT(false, "Unknown RendererAPI!");
	//	return nullptr;
	//}

	//Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t size)
	//{
	//	switch (Renderer::GetAPI())
	//	{
	//		case RendererAPI::None:		HG_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
	//		case RendererAPI::OpenGL:	return CreateRef<OpenGLIndexBuffer>(indices, size);
	//	}

	//	HG_CORE_ASSERT(false, "Unknown RendererAPI!");
	//	return nullptr;
	//}

}
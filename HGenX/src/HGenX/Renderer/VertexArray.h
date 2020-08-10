#pragma once

#include <memory>
#include "HGenX/Renderer/Buffer.h"

namespace HGenx {

	class VertexArray
	{
	public:
		virtual ~VertexArray(){}

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) = 0;
		virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) = 0;

		static VertexArray* Create();
		//static Ref<VertexBuffer> Create();
	};

}

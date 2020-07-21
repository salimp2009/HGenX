#pragma once

namespace HGenx {

	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() {}

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		static VertexBuffer* Create(float* vertices, uint32_t size);
		//static Ref<VertexBuffer> Create(float* vertices, uint32_t size);
	};
	
	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() {}

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		static IndexBuffer* Create(uint32_t* indices, uint32_t size);
		//static Ref<IndexBuffer> Create(uint32_t* indices, uint32_t size);  //TODO: Change above to Ref<> (shared pointer)
	};

}

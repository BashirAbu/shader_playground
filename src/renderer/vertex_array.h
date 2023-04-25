#pragma once
#include "core.h"
#include "buffer.h"
namespace SPG
{
	class VertexArray
	{
	public:
		virtual ~VertexArray() {}
		virtual void Bind() = 0;
		virtual void Unbind() = 0;
		virtual void SetVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) = 0;
		virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) = 0;
		virtual const std::shared_ptr<VertexBuffer>& GetVertexBuffer() const = 0;
		virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const = 0;
		static VertexArray* Create();
	};
}
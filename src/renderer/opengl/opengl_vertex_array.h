#pragma once
#include "core.h"
#include "renderer/vertex_array.h"
namespace SPG 
{
	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();
		virtual void Bind() override;
		virtual void Unbind() override;
		virtual void SetVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) override;
		virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) override;
		virtual const std::shared_ptr<VertexBuffer>& GetVertexBuffer() const 
		{
			return m_VertexBuffer;
		}
		virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const 
		{
			return m_IndexBuffer;
		}
	private:
		uint32_t m_ID;
		std::shared_ptr<VertexBuffer> m_VertexBuffer;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;
	};
}
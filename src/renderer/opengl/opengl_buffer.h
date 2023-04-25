#pragma once

#include "core.h"
#include "renderer/buffer.h"
namespace SPG 
{
	class OpenGLVertexBuffer : public VertexBuffer 
	{
	public:
		OpenGLVertexBuffer(float* vertices, uint32_t size);
		~OpenGLVertexBuffer();
		void Bind() override;
		void Unbind() override;
		virtual void SetLayout(const BufferLayout& layout) override;
		virtual const BufferLayout& GetLayout() const override;
		virtual uint32_t GetCount() override;

	private:
		uint32_t m_ID = 0;
		float* m_Vertices;
		uint32_t m_Size = 0;
		uint32_t m_Count = 0;
		BufferLayout m_Layout;
	};

	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(uint32_t* indices, uint32_t size);
		~OpenGLIndexBuffer();
		void Bind() override;
		void Unbind() override;
		virtual uint32_t GetCount() override;

	private:
		uint32_t m_ID = 0;
		uint32_t* m_Indices;
		uint32_t m_Size = 0;
		uint32_t m_Count = 0;
	};
}
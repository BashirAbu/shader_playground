#include "opengl_buffer.h"
#include "opengl_headers.h"
SPG::OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint32_t size) : m_Vertices(vertices), m_Size(size)
{
	m_Count = m_Size / sizeof(float);
	glCreateBuffers(1, &m_ID);
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

}

SPG::OpenGLVertexBuffer::~OpenGLVertexBuffer()
{
	glDeleteBuffers(1, &m_ID);
}

void SPG::OpenGLVertexBuffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}

void SPG::OpenGLVertexBuffer::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void SPG::OpenGLVertexBuffer::SetLayout(const BufferLayout& layout)
{
	m_Layout = layout;
}

const SPG::BufferLayout& SPG::OpenGLVertexBuffer::GetLayout() const
{
	return m_Layout;
}

uint32_t SPG::OpenGLVertexBuffer::GetCount()
{
	return m_Count;
}




SPG::OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indices, uint32_t size) : m_Indices(indices), m_Size(size)
{
	m_Count = m_Size / sizeof(uint32_t);
	glCreateBuffers(1, &m_ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

SPG::OpenGLIndexBuffer::~OpenGLIndexBuffer()
{
	glDeleteBuffers(1, &m_ID);
}

void SPG::OpenGLIndexBuffer::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

void SPG::OpenGLIndexBuffer::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

uint32_t SPG::OpenGLIndexBuffer::GetCount()
{
	return m_Count;
}

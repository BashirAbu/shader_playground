#include "opengl_vertex_array.h"
#include "opengl_headers.h"

static GLenum ShaderDataTypeToOpenGLDataType(SPG::ShaderDataType type) 
{
	switch (type)
	{
	case SPG::ShaderDataType::FLOAT: return GL_FLOAT;
		break;
	case SPG::ShaderDataType::FLOAT2: return GL_FLOAT;
		break;
	case SPG::ShaderDataType::FLOAT3: return GL_FLOAT;
		break;
	case SPG::ShaderDataType::FLOAT4: return GL_FLOAT;
		break;
	case SPG::ShaderDataType::INT: return GL_INT;
		break;
	case SPG::ShaderDataType::INT2: return GL_INT;
		break;
	case SPG::ShaderDataType::INT3: return GL_INT;
		break;
	case SPG::ShaderDataType::INT4: return GL_INT;
		break;
	case SPG::ShaderDataType::MAT3: return GL_FLOAT;
		break;
	case SPG::ShaderDataType::MAT4: return GL_FLOAT;
		break;
	case SPG::ShaderDataType::BOOL: return GL_BOOL;
		break;
	}
	SPG_LOG_FATAL("Data type not supported!.");
	return 0;
}

SPG::OpenGLVertexArray::OpenGLVertexArray()
{
	glGenVertexArrays(1, &m_ID);
}

SPG::OpenGLVertexArray::~OpenGLVertexArray()
{
	glDeleteVertexArrays(1, &m_ID);
}

void SPG::OpenGLVertexArray::Bind()
{
	glBindVertexArray(m_ID);
}

void SPG::OpenGLVertexArray::Unbind()
{
	glBindVertexArray(0);

}

void SPG::OpenGLVertexArray::SetVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
{
	assert(vertexBuffer->GetLayout().GetElements().size());
	m_VertexBuffer = vertexBuffer;

	glBindVertexArray(m_ID);
	m_VertexBuffer->Bind();
	uint32_t index = 0;
	for (BufferElement element : vertexBuffer->GetLayout().GetElements())
	{
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(
			index,
			element.GetComponentSize(element.Type),
			ShaderDataTypeToOpenGLDataType(element.Type),
			element.Normalize ? GL_TRUE : GL_FALSE,
			vertexBuffer->GetLayout().GetStride(),
			(void*)element.offset);
		index++;
	}
}

void SPG::OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
{
	m_IndexBuffer = indexBuffer;
	glBindVertexArray(m_ID);
	m_IndexBuffer->Bind();
}

#include "buffer.h"
#include "renderer_backend.h"
#ifdef SPG_WINDOWS
#include "opengl/opengl_buffer.h"
#endif
SPG::VertexBuffer* SPG::VertexBuffer::Create(float* vertices, uint32_t size)
{
	VertexBuffer* result = nullptr;
	if (SPG::RendererBackend::GetSingleton()->GetAPI() == RendererBackendAPI::OPENGL) 
	{
#ifdef SPG_WINDOWS
		result = new OpenGLVertexBuffer(vertices, size);
#endif
	}
	return result;

}


SPG::IndexBuffer* SPG::IndexBuffer::Create(uint32_t* indices, uint32_t size)
{
	IndexBuffer* result = nullptr;
	if (SPG::RendererBackend::GetSingleton()->GetAPI() == RendererBackendAPI::OPENGL)
	{
#ifdef SPG_WINDOWS
		result = new OpenGLIndexBuffer(indices, size);
#endif
	}
	return result;
}

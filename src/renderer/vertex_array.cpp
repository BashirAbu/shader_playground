#include "vertex_array.h"
#include "renderer_backend.h"
#ifdef SPG_WINDOWS
#include "opengl/opengl_vertex_array.h"
#endif // SPG_WINDOWS

SPG::VertexArray* SPG::VertexArray::Create()
{
	VertexArray* result = nullptr;
	if (SPG::RendererBackend::GetSingleton()->GetAPI() == RendererBackendAPI::OPENGL)
	{
#ifdef SPG_WINDOWS
		result = new OpenGLVertexArray();
#endif
	}
	return result;
}

#include "shader.h"
#include "renderer_backend.h"
#include "opengl/opengl_shader.h"
namespace SPG 
{
	Shader* Shader::Create(const char* vertexShaderSource, const char* fragmentShaderSource)
	{
		Shader* result = nullptr;
		if (RendererBackend::GetSingleton()->GetAPI() == RendererBackendAPI::OPENGL)
		{
			result = new OpenGLShader(vertexShaderSource, fragmentShaderSource);
		}
		return result;
	}
}
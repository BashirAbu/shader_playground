#pragma once
#include "core.h"
#include "renderer/shader.h"
namespace SPG
{
	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const char* vertexShaderSource, const char* fragmentShaderSource);
		virtual ~OpenGLShader();

		void Bind() override;
		void Unbind() override;
		void UploadUniformMat4(const char* name, const Mat4f& mat) override;
		void UploadUniformVec4f(const char* name, const Vector4f& vec4) override;
	private:
		uint32_t m_ProgramID;
	};
}
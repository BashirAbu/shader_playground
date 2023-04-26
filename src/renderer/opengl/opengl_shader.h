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
		void Recompile(const char* vertexShaderSource, const char* fragmentShaderSource);
		void Bind() override;
		void Unbind() override;
		void UploadUniform1f(const char* name, float value) override;
		void UploadUniformMat4(const char* name, const Mat4f& mat) override;
		void UploadUniformVec2f(const char* name, const Vector2f& vec2) override;
		void UploadUniformVec3f(const char* name, const Vector3f& vec3) override;
		void UploadUniformVec4f(const char* name, const Vector4f& vec4) override;
	private:
		uint32_t m_ProgramID;
	};
}
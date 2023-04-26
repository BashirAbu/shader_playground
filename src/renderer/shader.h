#pragma once
#include "core.h"
#include "math/spg_maths.h"
namespace SPG
{
	class Shader
	{
	public:
		virtual ~Shader() {}
		virtual void Recompile(const char* vertexShaderSource, const char* fragmentShaderSource) = 0;
		virtual void Bind() = 0;
		virtual void Unbind() = 0;
		virtual void UploadUniform1i(const char* name, int value) = 0;
		virtual void UploadUniform1f(const char* name, float value) = 0;
		virtual void UploadUniformMat4(const char* name, const Mat4f& mat) = 0;
		virtual void UploadUniformVec2f(const char* name, const Vector2f& vec2) = 0;
		virtual void UploadUniformVec3f(const char* name, const Vector3f& vec3) = 0;
		virtual void UploadUniformVec4f(const char* name, const Vector4f& vec4) = 0;
		static Shader* Create(const char* vertexShaderSource, const char* fragmentShaderSource);
	};

}
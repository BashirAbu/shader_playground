#include "opengl_shader.h"
#include "opengl_headers.h"
#include "math/spg_maths.h"
namespace SPG
{
#define OPENGL_SHADER_COMPILATION_STATUS(__shaderObj)\
{\
    int32_t __success;\
    char __infoLog[512];\
    glGetShaderiv(__shaderObj, GL_COMPILE_STATUS, &__success);\
    if(!__success)\
    {\
        glGetShaderInfoLog(__shaderObj, 512, 0, __infoLog);\
        SPG_LOG_TEXT("[OPENGL][SHADER COMPILATION]: %s\n", __infoLog);\
    }\
    else\
    {\
        SPG_LOG_TEXT("[OPENGL][SHADER COMPILATION]: Success.\n")\
    }\
}

#define OPENGL_PROGRAM_LINK_STATUS(__program)\
{\
    int32_t __success;\
    char __infoLog[512];\
    glGetProgramiv(__program, GL_LINK_STATUS, &__success);\
    if(!__success)\
    {\
        glGetProgramInfoLog(__program, 512, 0, __infoLog);\
        SPG_LOG_TEXT("[OPENGL][PROGRAM LINK]: %s\n", __infoLog);\
    }\
    else\
    {\
        SPG_LOG_TEXT("[OPENGL][PROGRAM LINK]: Success.\n")\
    }\
}
	OpenGLShader::OpenGLShader(const char* vertexShaderSource, const char* fragmentShaderSource)
	{
        uint32_t vertexShader = 0;
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, 0);
        glCompileShader(vertexShader);
        OPENGL_SHADER_COMPILATION_STATUS(vertexShader);
        GLuint fragmentShader = 0;
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);
        OPENGL_SHADER_COMPILATION_STATUS(fragmentShader);
        m_ProgramID = glCreateProgram();
        glAttachShader(m_ProgramID, vertexShader);
        glAttachShader(m_ProgramID, fragmentShader);
        glLinkProgram(m_ProgramID);
        OPENGL_PROGRAM_LINK_STATUS(m_ProgramID);
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
	}
	OpenGLShader::~OpenGLShader()
	{
        glDeleteProgram(m_ProgramID);
	}
	void OpenGLShader::Bind()
	{
        glUseProgram(m_ProgramID);
	}
	void OpenGLShader::Unbind()
	{
        glUseProgram(0);
	}
    void OpenGLShader::UploadUniformMat4(const char* name, const Mat4f& mat)
    {
        glUseProgram(m_ProgramID);
        int32_t location = glGetUniformLocation(m_ProgramID, name);
        if (location == -1)
        {
            SPG_LOG_ERROR("%s uniform does not exist", name);
        }
        glUniformMatrix4fv(location, 1, GL_FALSE, mat.Data);
    }

    void OpenGLShader::UploadUniformVec4f(const char* name, const Vector4f& vec4)
    {
        glUseProgram(m_ProgramID);
        int32_t location = glGetUniformLocation(m_ProgramID, name);
        if (location == -1)
        {
            SPG_LOG_ERROR("%s uniform does not exist", name);
        }
        glUniform4fv(location, 1, vec4.elements);
    }
}
#include "opengl_texture.h"
#include "opengl_headers.h"
#include "stb_image.h"
namespace SPG
{
    OpenGLTexture::OpenGLTexture(const TextureSpecs& specs)
    {
        _specs = specs;
        glGenTextures(1, &_id);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, _id);
        if(strcmp(specs.filepath, "") == 0)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _specs.width, _specs.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);      
        }
        else
        {
            int32_t channelsInFile = 0;
            uint8_t* data = stbi_load(_specs.filepath, &_specs.width, &_specs.height, &channelsInFile, NULL);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _specs.width, _specs.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            stbi_image_free(data);
        }
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    
    OpenGLTexture::~OpenGLTexture()
    {
		glDeleteTextures(1, &_id);
    }
    
    void OpenGLTexture::Bind()
    {
        glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, _id);
    }
    
    void OpenGLTexture::Unbind()
    {
		glBindTexture(GL_TEXTURE_2D, 0);
    }
    const uint32_t OpenGLTexture::GetID() const 
    {
        return _id;
    }
    
    const Vector2i OpenGLTexture::GetSize() const 
    {
        return _size;
    }
}
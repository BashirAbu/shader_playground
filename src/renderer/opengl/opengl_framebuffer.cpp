#include "opengl_framebuffer.h"
#include "opengl_headers.h"

namespace SPG
{
    OpenGLFramebuffer::OpenGLFramebuffer(const FramebufferSpecs& specs)
    {
        _specs = specs;
        Recreate(specs);
    }
    
    void OpenGLFramebuffer::Recreate(const FramebufferSpecs& specs)
    {
        if(_init)
        {
            glDeleteFramebuffers(1, &_id);
            colorAttachment.reset();
        }
        _init = true;

        glGenFramebuffers(1, &_id);
		glBindFramebuffer(GL_FRAMEBUFFER, _id);

		TextureSpecs textSpecs = {specs.width, specs.height};
        colorAttachment = std::make_shared<OpenGLTexture>(textSpecs);
        colorAttachment->Bind();
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colorAttachment->GetID(), 0);
		assert(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		colorAttachment->Unbind();        
    }
    OpenGLFramebuffer::~OpenGLFramebuffer()
    {
        glDeleteFramebuffers(1, &_id);
    }
    
    void OpenGLFramebuffer::Bind()
    {
		colorAttachment->Bind();
        glBindFramebuffer(GL_FRAMEBUFFER, _id);
    }
    
    void OpenGLFramebuffer::Unbind()
    {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
		colorAttachment->Unbind();
    }
    
}
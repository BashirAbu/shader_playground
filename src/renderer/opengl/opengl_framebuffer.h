#pragma once
#include "core.h"
#include "renderer/framebuffer.h"
#include "opengl_texture.h"
namespace SPG
{
    class OpenGLFramebuffer : public Framebuffer
    {
    public:
        OpenGLFramebuffer(const FramebufferSpecs& specs);
        ~OpenGLFramebuffer();
        virtual void Bind() override;
        virtual void Unbind() override;
        virtual void Recreate(const FramebufferSpecs& specs) override;
        virtual const std::shared_ptr<Texture>& GetColorAttachment() const override;
    private:
        uint32_t _id;
        FramebufferSpecs _specs;
        std::shared_ptr<OpenGLTexture> colorAttachment;
        bool _init = false;
    };
}
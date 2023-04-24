#pragma once
#include "core.h"
#include "texture.h"
namespace SPG
{
    struct FramebufferSpecs
    {
        int32_t width = 0;
        int32_t height = 0;
    };
    class Framebuffer
    {
    public:
        static Framebuffer* Create(const FramebufferSpecs& specs);
        virtual ~Framebuffer(){}
        virtual void Recreate(const FramebufferSpecs& specs) = 0;
        virtual void Bind() = 0;
        virtual void Unbind() = 0;
        virtual const std::shared_ptr<Texture>& GetColorAttachment() const = 0;
    private:
    };
}
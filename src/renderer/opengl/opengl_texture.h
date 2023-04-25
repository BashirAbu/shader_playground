#pragma once
#include "core.h"
#include "renderer/texture.h"
namespace SPG
{
    class OpenGLTexture : public Texture
    {
    public:
        OpenGLTexture(const TextureSpecs& specs);
        ~OpenGLTexture();
        virtual void Bind() override;
        virtual void Unbind() override;
        const uint32_t GetID() const override;
        virtual void UpdateData(void* data, int32_t width, int32_t height) override;
        virtual const void* GetTextureData() override;
        virtual const Vector2i GetSize() const override;
    private:
        uint32_t _id;
        Vector2i _size;
        TextureSpecs _specs;
        uint32_t* _textureData = nullptr;
        uint32_t _internalFormat;
    };
}
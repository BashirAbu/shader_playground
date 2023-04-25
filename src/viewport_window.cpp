#include "viewport_window.h"
#include "renderer/render_command.h"
namespace SPG
{
    const char* defVertShader = R"(
                    #version 330
                    layout (location = 0) in vec3 aPosition;
                    void main()
                    {
                        gl_Position = vec4(aPosition, 1.0);
                    }
                    )";
    const char* defFragShader = R"(
                    #version 330
                    out vec4 FragColor;
                    void main()
                    { 
                        FragColor = vec4(1.0f, 0.0f, 1.0f, 1.0f);
                    }
                    )";
    Surface::Surface()
    {
        _shader = std::shared_ptr<Shader>(Shader::Create(defVertShader, defFragShader));
        float vertices[] = 
        {
            1.0f, 1.0f, 0.0f, // top right
            1.0, -1.0f, 0.0f, // bottom right
            -1.0f, -1.0f, 0.0f, //bottom left
            -1.0f, 1.0f, 0.0f // top left
        };

        uint32_t indices[]
        {
            0,1,3,
            1,2,3
        };
        _vertexBuffer = std::shared_ptr<VertexBuffer>(VertexBuffer::Create(vertices, sizeof(vertices)));
        _indexBuffer = std::shared_ptr<IndexBuffer>(IndexBuffer::Create(indices, sizeof(indices)));
        _vertexArray = std::shared_ptr<VertexArray>(VertexArray::Create());
        _vertexArray->Bind();
        BufferLayout layout = 
        {
            {ShaderDataType::FLOAT3, "aPosition"}
        };
        _vertexBuffer->SetLayout(layout);
        _vertexArray->SetVertexBuffer(_vertexBuffer);
        _vertexArray->SetIndexBuffer(_indexBuffer);
        _vertexArray->Unbind();
    }
    
    Surface::~Surface()
    {
        
    }
    
    void Surface::Render()
    {
        _shader->Bind();
        _vertexArray->Bind();
        RenderCommand::DrawIndexed(_vertexArray);
        _shader->Unbind();
        _vertexArray->Unbind();

    }

    ViewportWidnow::ViewportWidnow()
    {
        _viewPortFlags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse;
        FramebufferSpecs framebufferSpecs = {500, 500};
        
        _framebuffer = std::shared_ptr<Framebuffer>(Framebuffer::Create(framebufferSpecs));
        TextureSpecs renderTexSpecs;
        _renderTex = std::shared_ptr<Texture>(Texture::Create(renderTexSpecs));

        _surface = std::make_shared<Surface>();
    }

    ViewportWidnow::~ViewportWidnow()
    {
        
    }
    void ViewportWidnow::Show()
    {
       
        ImGui::Begin("Viewport");
        { 
            {
                RenderCommand::SetViewportSize(_framebuffer->GetColorAttachment()->GetSize().X, _framebuffer->GetColorAttachment()->GetSize().Y);
                _framebuffer->Bind();
                RenderCommand::SetClearColor(1.0f, 1.0f, 0.0f, 1.0f);
                RenderCommand::Clear();
                //Render the thing.
                _surface->Render();
                //
                _framebuffer->Unbind();
                ImGuiViewport* viewPort = ImGui::GetMainViewport();
                RenderCommand::SetViewportSize((int32_t)viewPort->Size.x, (int32_t)viewPort->Size.y);
            }

            _renderTex->UpdateData((void*)_framebuffer->GetColorAttachment()->GetTextureData(), _framebuffer->GetColorAttachment()->GetSize().X, _framebuffer->GetColorAttachment()->GetSize().Y);
            size = ImGui::GetWindowSize();
            
            ImVec2 imageSize;
            {
                ImVec2 offset;
                int32_t desiredWidth = (int32_t)size.x;
                int32_t desiredHeight = (int32_t)(desiredWidth * (1.0f / _aspectRatio));

                if(desiredHeight > size.y)
                {
                    desiredHeight = (int32_t)size.y;
                    desiredWidth = (int32_t)(size.y * _aspectRatio);

                    offset.x = (size.x / 2) - ((float)desiredWidth / 2.0f);
                    offset.y = (size.y / 2) - ((float)desiredHeight / 2.0f);
                }
                else
                {
                    offset.x = (size.x / 2) - ((float)desiredWidth / 2.0f);
                    offset.y = (size.y / 2) - ((float)desiredHeight / 2.0f);
                }

                imageSize.x = (float)desiredWidth;
                imageSize.y = (float)desiredHeight;
                ImGui::SetCursorPos(offset);
            }
            ImGui::Image((void*)(intptr_t)_renderTex->GetID(), imageSize);
        }
        ImGui::End(); 
    }
}
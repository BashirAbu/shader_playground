#include "viewport_window.h"
#include "renderer/render_command.h"
#include "application.h"
#include "renderer/opengl/opengl_headers.h"
#include "stb_image_write.h"
#include <filesystem>
namespace SPG
{
    const char* defVertShader = R"(
                    #version 330
                    layout (location = 0) in vec3 aPosition;
                    layout (location = 1) in vec2 aCoord;
                    out vec2 fragCoord;
                    void main()
                    {
                        gl_Position = vec4(aPosition, 1.0);
                        fragCoord = aCoord;
                    }
                    )";
    const char* defFragShader = R"(
                    #version 330
                    in vec2 fragCoord;
                    out vec4 FragColor;
                    void main()
                    { 
                        FragColor = vec4(0.0f, 0.0f, 0.0f, 1.0f);
                    }
    )";
    const char* topFragShader = R"(
                    #version 330
                    in vec2 fragCoord;
                    out vec4 FragColor;
                    uniform vec2 iResolution;
                    uniform float iTime;
                    uniform int iFrame;
                    )";
    const char* bottomFragShader = R"(
                    void main()
                    {
                        mainImage(FragColor, fragCoord);
                    }
    )";
    Surface::Surface(const Vector2i& framebufferSize)
    {
        _shaderBuffer = new char[70000];
        Recreate(framebufferSize);
    }
    
    void Surface::Recreate(const Vector2i& framebufferSize)
    {
        static bool init = false;
        if(init)
        {
            _vertexBuffer.reset();
            _indexBuffer.reset();
            _vertexArray.reset();
        }
        init = true;
        Vector2i res = framebufferSize;
        _shader = std::shared_ptr<Shader>(Shader::Create(defVertShader, defFragShader));
        float vertices[] = 
        {
             //aPosition        aCoord
             1.0f,  1.0f, 0.0f, (float)res.X, 0.0f, //top right
             1.0f, -1.0f, 0.0f, (float)res.X, (float)res.Y, //bottom right
            -1.0f, -1.0f, 0.0f, 0.0f,         (float)res.Y, //bottom left
            -1.0f,  1.0f, 0.0f, 0.0f,         0.0f  //top left
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
            {ShaderDataType::FLOAT3, "aPosition"},
            {ShaderDataType::FLOAT2, "aCoord"}
        };
        _vertexBuffer->SetLayout(layout);
        _vertexArray->SetVertexBuffer(_vertexBuffer);
        _vertexArray->SetIndexBuffer(_indexBuffer);
        _vertexArray->Unbind();
    }
    
    void Surface::RecompileShader()
    {
        memset(_shaderBuffer, 0, 70000 * sizeof(char));
        snprintf(_shaderBuffer, 70000 * sizeof(_shaderBuffer), "%s\n%s\n%s\0", topFragShader, Application::GetScriptBuffer(), bottomFragShader);
        _shader->Recompile(defVertShader, _shaderBuffer);
    }
    Surface::~Surface()
    {
        delete _shaderBuffer;
    }
    
    void Surface::Render()
    {
        _shader->Bind();
        _shader->UploadUniformVec2f("iResolution", Vector2f((float)Application::GetViewportFramebufferSize().X, (float)Application::GetViewportFramebufferSize().Y));
        _shader->UploadUniform1f("iTime", Application::GetTime());
        _shader->UploadUniform1i("iFrame", (int)Application::GetNumberOfRenderedFrames());
        _vertexArray->Bind();
        RenderCommand::DrawIndexed(_vertexArray);
        _shader->Unbind();
        _vertexArray->Unbind();

    }
    ViewportWidnow::ViewportWidnow()
    {
        _viewPortFlags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove;
        FramebufferSpecs framebufferSpecs;
        framebufferSpecs.width = Application::GetSettings().framebufferSize.X;
        framebufferSpecs.height = Application::GetSettings().framebufferSize.Y;
        _framebuffer = Framebuffer::Create(framebufferSpecs);
        TextureSpecs renderTexSpecs;
        renderTexSpecs.width = framebufferSpecs.width;
        renderTexSpecs.height = framebufferSpecs.height;
        _renderTex = std::shared_ptr<Texture>(Texture::Create(renderTexSpecs));
        _surface = std::make_shared<Surface>(Vector2i(framebufferSpecs.width, framebufferSpecs.height));
    }

    ViewportWidnow::~ViewportWidnow()
    {
        
    }
    void ViewportWidnow::Show()
    {
        
        ImGui::Begin("Viewport", nullptr, _viewPortFlags);
        {
            
            {
                
                RenderCommand::SetViewportSize(_framebuffer->GetColorAttachment()->GetSize().X, _framebuffer->GetColorAttachment()->GetSize().Y);
                _framebuffer->Bind();
                RenderCommand::SetClearColor(0.0f, 1.0f, 0.0f, 1.0f);
                RenderCommand::Clear();
                //Render the thing.
                _surface->Render();
                //
                _framebuffer->Unbind();
                ImGuiViewport* viewPort = ImGui::GetMainViewport();
                RenderCommand::SetViewportSize((int32_t)viewPort->Size.x, (int32_t)viewPort->Size.y);
            }
            _renderTex->Copy(_framebuffer->GetColorAttachment()->GetID(), _framebuffer->GetColorAttachment()->GetSize().X, _framebuffer->GetColorAttachment()->GetSize().Y);
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


            ImVec2 avArea = ImGui::GetContentRegionAvail();
            ImGui::SetCursorPos({(avArea.x / 2) - 25, 30});
            ImGui::Text("FPS: %.0f", 1.0f / Application::GetDeltaTime());
            ImGui::SetCursorPos({(avArea.x / 2) - 65, 60});
            if(ImGui::Button("Compile"))
            {
                _surface->RecompileShader();
            }
            ImGui::SameLine();
            if(ImGui::Button("Screenshot"))
            {
                const void* screenshotData = _framebuffer->GetColorAttachment()->GetTextureData();
                std::string path = Application::GetProjectPath();
                std::size_t pos = path.find(".shader_playground"); // Find the position of the substring in the string
                if (pos != std::string::npos) { // If the substring was found
                    path.erase(pos, 18); // Remove the substring from the string
                }
                if(path == "")
                {
                    path = "data\\";
                    path = path + "screenshots\\";
                }
                else 
                {
                    path = path + "\\screenshots\\";
                    std::filesystem::path dirPath = path;
                    if (!std::filesystem::exists(dirPath))
                        std::filesystem::create_directories(dirPath);
                }
                
                std::string name = "screenshot_" + std::to_string(Application::GetTime()) + ".png";
                name =  path == "data\\screenshots\\"? path + "untitled_" + name :  path + name;

                if(!stbi_write_png(name.c_str(),  _framebuffer->GetColorAttachment()->GetSize().X,  _framebuffer->GetColorAttachment()->GetSize().Y, 3, screenshotData,  _framebuffer->GetColorAttachment()->GetSize().X * 3))
                {
                    SPG_LOG_ERROR("Cannot take screenshot. Path: %s", name.c_str());
                }
            }
            
        }
        ImGui::End();    
    }
    
    const Vector2i& ViewportWidnow::GetFramebufferSize() const
    {
        return _framebuffer->GetColorAttachment()->GetSize();
    }
    
    void ViewportWidnow::OnFramebufferSizeChange()
    {
        FramebufferSpecs specs;
        specs.width = Application::GetSettings().framebufferSize.X;
        specs.height = Application::GetSettings().framebufferSize.Y;
        _framebuffer->Recreate(specs);
        _surface->Recreate({specs.width, specs.height});
        _surface->RecompileShader();
    }
}
#include "editor_window.h"
#include "application.h"
#include <string>
namespace SPG
{
    EditorWidnow::EditorWidnow()
    {
        _editorFlags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove;
        _scriptBuffer = new char[SCRIPT_BUFFER_SIZE];
        memset(_scriptBuffer, 0, SCRIPT_BUFFER_SIZE * sizeof(char));
        const char* temp = 
R"(void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    vec2 uv = fragCoord/iResolution.xy;

    vec3 col = 0.5 + 0.5*cos(iTime+uv.xyx+vec3(0,2,4));

    fragColor = vec4(col,1.0);
})";
        strcpy(_scriptBuffer, temp);
    }

    EditorWidnow::~EditorWidnow()
    {
        delete _scriptBuffer;
    }
    void EditorWidnow::Show()
    {
        ImGui::Begin("Editor", nullptr, _editorFlags);
        {
            size = ImGui::GetContentRegionAvail();
            ImGui::PushStyleColor(ImGuiCol_Text, *((ImVec4*) &(Application::GetSettings().fontColor.elements))); // Red color
            ImGui::InputTextMultiline("edit", _scriptBuffer, SCRIPT_BUFFER_SIZE, size, ImGuiInputTextFlags_AllowTabInput);
            ImGui::PopStyleColor();
        }
            ImGui::End();
    }
    
    char* EditorWidnow::GetScriptBuffer()
    {
        return _scriptBuffer;
    }
    
    void EditorWidnow::SetScriptBuffer(void* data, size_t size)
    {
        memset(_scriptBuffer, 0, SCRIPT_BUFFER_SIZE * sizeof(char));
        strcpy(_scriptBuffer, (char*)data);
    }

}
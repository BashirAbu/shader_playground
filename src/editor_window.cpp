#include "editor_window.h"
#include <string>
namespace SPG
{
    EditorWidnow::EditorWidnow()
    {
        _editorFlags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse;
        _scriptBuffer = new char[65000];
        memset(_scriptBuffer, 0, 65000 * sizeof(char));
    }

    EditorWidnow::~EditorWidnow()
    {
        delete _scriptBuffer;
    }
    void EditorWidnow::Show()
    {
        ImGui::Begin("Editor");
        {
            size = ImGui::GetContentRegionAvail();
            ImGui::InputTextMultiline("edit", _scriptBuffer, 65000, size, ImGuiInputTextFlags_AllowTabInput);
        }
        ImGui::End();
    }
    
    char* EditorWidnow::GetScriptBuffer()
    {
        return _scriptBuffer;
    }
}
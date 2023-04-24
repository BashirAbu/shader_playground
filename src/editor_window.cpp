#include "editor_window.h"
namespace SPG
{
    EditorWidnow::EditorWidnow()
    {
        _editorFlags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse;
    }

    EditorWidnow::~EditorWidnow()
    {
        
    }
    void EditorWidnow::Show()
    {
        ImGui::Begin("Editor");
        {

        }
        ImGui::End();
    }
}
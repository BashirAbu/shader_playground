#pragma once
#include "core.h"
#include "ImGui/spg_imgui.h"
namespace SPG
{
    class EditorWidnow
    {
        public:
        EditorWidnow();
        ~EditorWidnow();
        void Show();
        char* GetScriptBuffer();
        ImVec2 size;
        private:
        char* _scriptBuffer;
        ImGuiWindowFlags _editorFlags = 0;
    };
}
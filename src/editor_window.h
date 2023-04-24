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

        ImVec2 size;
        private:
        ImGuiWindowFlags _editorFlags = 0;
    };
}
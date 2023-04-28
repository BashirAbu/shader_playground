#pragma once
#include "core.h"
#include "ImGui/spg_imgui.h"
namespace SPG
{
    #define SCRIPT_BUFFER_SIZE 65000
    class EditorWidnow
    {
        public:
        EditorWidnow();
        ~EditorWidnow();
        void Show();
        char* GetScriptBuffer();
        void SetScriptBuffer(void* data, size_t size);
        ImVec2 size;
        private:
        char* _scriptBuffer;
        ImGuiWindowFlags _editorFlags = 0;
    };
}
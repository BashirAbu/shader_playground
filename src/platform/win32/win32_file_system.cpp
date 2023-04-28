#include "win32_file_system.h"
#include <Windows.h>
#include <stdio.h>
#include "application.h"
namespace SPG
{
    Win32FileSystem::Win32FileSystem()
    {
        
    }
    
    Win32FileSystem::~Win32FileSystem()
    {
        
    }
    
    FileData Win32FileSystem::InternalOpenFile(const char* filepath)
    {
        FileData result = {0};
        if(filepath[0] == '\0')
            return result;
        FILE* file;
        file = fopen(filepath, "r");
        if(file)
        {
            fseek(file, 0, SEEK_END);
            result.size = ftell(file);
            rewind(file);
            result.data = (void*)new uint8_t[result.size];
            fread(result.data, result.size, 1, file);
            fclose(file); 
        }
        else
        {
            SPG_LOG_ERROR("Cannot open file %s.", filepath);
        }
        return result;
    }
    
    void Win32FileSystem::InternalWriteToFile(const char* filepath, void* data, size_t size, OpenMode mode)
    {
        FILE* file;
        switch (mode)
        {
            case OpenMode::Append: file = fopen(filepath, "a"); break;
            case OpenMode::Overwrite: file = fopen(filepath, "w"); break;
        }

        if(file)
        {
            fwrite(data, size, 1, file);
            fclose(file);
        }
        else
        {
            SPG_LOG_ERROR("Cannot write to file %s.", filepath);
        }
    }
    
    std::string Win32FileSystem::InternalOpenFileDialog(void* windowHandle)
    {
        std::string result = "null";
        OPENFILENAMEA ofn;
        char file_name [256];
        ZeroMemory(&ofn, sizeof(OPENFILENAME));
        ofn.lStructSize = sizeof(OPENFILENAME);
        ofn.hwndOwner = (HWND)windowHandle;
        ofn.lpstrFile = file_name;
        ofn.lpstrFile[0] = '\0';
        ofn.nMaxFile = 256;
        ofn.lpstrFilter = "All Files\0*.*\0Shader Playground Project\0*.shader_playground\0";
        ofn.nFilterIndex = 2;
        GetOpenFileNameA(&ofn);
        result = ofn.lpstrFile;
        return result;
    }
    
    std::string Win32FileSystem::InternalSaveAsDialog(void* windowHandle)
    {
        std::string result = "";
        OPENFILENAMEA ofn;
        char file_name [256];
        ZeroMemory(&ofn, sizeof(OPENFILENAME));
        ofn.lStructSize = sizeof(OPENFILENAME);
        ofn.hwndOwner = (HWND)windowHandle;
        ofn.lpstrFile = file_name;
        ofn.lpstrFile[0] = '\0';
        ofn.nMaxFile = 256;
        ofn.lpstrFilter = "All Files\0*.*\0Shader Playground Project\0*.shader_playground\0";
        ofn.nFilterIndex = 1;     
        GetSaveFileNameA(&ofn);
        result = ofn.lpstrFile;
        return result;
    }
}
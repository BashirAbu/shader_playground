#pragma once
#include "core.h"

namespace SPG
{
    class Window;
    struct FileData
    {
        FileData(){}
        //move constructor
        FileData(FileData&& fileData)
        {
            size = fileData.size;
            data = fileData.data;
            fileData.data = nullptr;
        }
        ~FileData()
        {
            if(data)
            {
                free(data);
                data = nullptr;
            }
        }
        size_t size = 0;
        void* data = nullptr;
    };
    enum class OpenMode
    {
        Append = 0,
        Overwrite
    };
    class FileSystem
    {
    public:
        virtual ~FileSystem() {};
        static FileData OpenFile(const char* filepath) { return GetSingleton()->InternalOpenFile(filepath); }
        static void WriteToFile(const char* filepath, void* data, size_t size, OpenMode mode) { GetSingleton()->InternalWriteToFile(filepath, data, size, mode); }
        static FileSystem* GetSingleton();
        static std::string OpenFileDialog(void* windowHandle) { return GetSingleton()->InternalOpenFileDialog(windowHandle); }
        static std::string SaveAsDialog(void* windowHandle) { return GetSingleton()->InternalSaveAsDialog(windowHandle); }
    protected:
        FileSystem() {}
        virtual FileData InternalOpenFile(const char* filepath) = 0;
        virtual void InternalWriteToFile(const char* filepath, void* data, size_t size, OpenMode mode) = 0;
        virtual std::string InternalOpenFileDialog(void* windowHandle) = 0;
        virtual std::string InternalSaveAsDialog(void* windowHandle) = 0;
    };
}

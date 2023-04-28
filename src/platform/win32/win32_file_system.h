#pragma once
#include "core.h"
#include "file_system.h"

namespace SPG
{
    class Win32FileSystem : public FileSystem
    {
    public:
        Win32FileSystem();
        ~Win32FileSystem();

        FileData InternalOpenFile(const char* filepath) override;
        void InternalWriteToFile(const char* filepath, void* data, size_t size, OpenMode mode) override;
        std::string InternalOpenFileDialog(void* windowHandle) override;

    private:
    };
} // namespace SPG

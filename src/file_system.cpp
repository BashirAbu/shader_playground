#include "file_system.h"
#include "platform/win32/win32_file_system.h"
namespace SPG
{
    
    FileSystem* FileSystem::GetSingleton()
    {
        static FileSystem* singleton = nullptr;
        if(!singleton)
        {
            singleton = new Win32FileSystem();
        }
        return singleton;
    }

    
} // namespace SPG

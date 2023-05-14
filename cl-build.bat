set arg1=%1
call vcvarsall x64
set FLAGS=/EHsc /utf-8 /Od /MP /MT /W3 /wd4312 /wd4172 /wd4127 /wd4530 /wd4459 /wd5105 /wd4100 /wd4996 /std:c++17 /Z7
set DEFINES=/D SPG_WINDOWS /D SPG_DEBUG
if "%arg1%"=="release" (
     set FLAGS=/EHsc /utf-8 /Od /MP /MT /W3 /wd4312 /wd4172 /wd4127 /wd4530 /wd4459 /wd5105 /wd4100 /wd4996 /std:c++17
     set DEFINES=/D SPG_WINDOWS
)
set OUTPUT=/Fo:bin/bin-int/ /Fe:bin/shader_playground.exe
set SRC=src/*.cpp src/renderer/*.cpp src/renderer/opengl/*.cpp src/platform/win32/*.cpp src/platform/win32/opengl/*.cpp src/ImGui/*.cpp third_party/dear_imgui/imgui.cpp third_party/dear_imgui/imgui_draw.cpp third_party/dear_imgui/imgui_demo.cpp third_party/dear_imgui/imgui_tables.cpp third_party/dear_imgui/imgui_widgets.cpp third_party/dear_imgui/backends/imgui_impl_opengl3.cpp  third_party/dear_imgui/backends/imgui_impl_win32.cpp third_party/stb_image/stb_image.cpp third_party/tinyxml2/tinyxml2.cpp
set LIBS=Comdlg32.lib user32.lib gdi32.lib
set INCLUDES=/I src/ /I third_party/  /I third_party/dear_imgui/  /I third_party/dear_imgui/backends /I third_party/stb_image
cl.exe %OUTPUT% %FLAGS% %DEFINES% %SRC% %INCLUDES% %LIBS%

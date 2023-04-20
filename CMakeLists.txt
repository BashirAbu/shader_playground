cmake_minimum_required(VERSION 3.0.0)

project(shader_playground VERSION 0.1.0 LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 17)
add_compile_definitions(UNICODE=_UNICODE)
if(WIN32)
	add_compile_definitions(SPG_WINDOWS=1)
	if(MSVC)
		add_compile_options("/utf-8" "/MDd" "/Zi" "/W3" "/wd4127" "/wd4530" "/wd4459" "/wd5105" "/wd4100" "/wd4996")
		if(CMAKE_BUILD_TYPE MATCHES  "Debug")
			add_compile_definitions(SPG_DEBUG=1)
			add_compile_options("/Od") 
		endif()
	endif()
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/cmake_files/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/cmake_files/bin)



set (SOURCE_FILES 
     "src/main.cpp"
	 "src/window.cpp"
	 "src/application.cpp"
	 "src/renderer/renderer_backend.cpp"
	 "src/renderer/renderer_api.cpp"
	 "src/renderer/render_command.cpp"
	 "src/renderer/opengl/opengl_renderer_api.cpp"
	 "src/platform/win32/win32_window.cpp"
	 "src/platform/win32/opengl/win32_renderer_backend.cpp"
	 "src/platform/win32/win32_imgui.cpp"
	 "third_party/dear_imgui/imgui.cpp"
	 "third_party/dear_imgui/imgui_draw.cpp"
	 "third_party/dear_imgui/imgui_demo.cpp"
	 "third_party/dear_imgui/imgui_tables.cpp"
	 "third_party/dear_imgui/imgui_widgets.cpp"
	 "third_party/dear_imgui/backends/imgui_impl_opengl3.cpp"
	 "third_party/dear_imgui/backends/imgui_impl_win32.cpp"
  )

add_executable(shader_playground ${SOURCE_FILES})

target_include_directories(shader_playground PUBLIC "src/")
target_include_directories(shader_playground PUBLIC "third_party/dear_imgui/")
target_include_directories(shader_playground PUBLIC "third_party/dear_imgui/backends")





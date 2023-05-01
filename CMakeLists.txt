cmake_minimum_required(VERSION 3.0.0)

project(shader_playground VERSION 0.1.0 LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 17)
add_compile_definitions(UNICODE=_UNICODE)
if(WIN32)
	add_compile_definitions(SPG_WINDOWS=1)
	if(MSVC)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8 /MDd /Zi /MP /W3 /wd4312 /wd4172 /wd4127 /wd4530 /wd4459 /wd5105 /wd4100 /wd4996")
		if(CMAKE_BUILD_TYPE MATCHES "Debug")
			add_compile_definitions(SPG_DEBUG=1)
			set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Od")
		elseif(CMAKE_BUILD_TYPE MATCHES "Release")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Ox")
		endif()
	endif()
	message(STATUS "CMAKE_CXX_FLAGS : ${CMAKE_CXX_FLAGS}")
	message(STATUS "CMAKE_C_FLAGS : ${CMAKE_CXX_FLAGS}")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/cmake_files/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/cmake_files/bin)



set (SOURCE_FILES 
     "src/main.cpp"
	 "src/window.cpp"
	 "src/application.cpp"
	 "src/editor_window.cpp"
	 "src/viewport_window.cpp"
	 "src/file_system.cpp"
	 "src/renderer/renderer_backend.cpp"
	 "src/renderer/renderer_api.cpp"
	 "src/renderer/render_command.cpp"
	 "src/renderer/texture.cpp"
	 "src/renderer/framebuffer.cpp"
	 "src/renderer/shader.cpp"
	 "src/renderer/buffer.cpp"
	 "src/renderer/vertex_array.cpp"
	 "src/renderer/opengl/opengl_renderer_api.cpp"
	 "src/renderer/opengl/opengl_texture.cpp"
	 "src/renderer/opengl/opengl_framebuffer.cpp"
	 "src/renderer/opengl/opengl_shader.cpp"
	 "src/renderer/opengl/opengl_vertex_array.cpp"
	 "src/renderer/opengl/opengl_buffer.cpp"
	 "src/platform/win32/win32_window.cpp"
	 "src/platform/win32/win32_imgui.cpp"
	 "src/platform/win32/win32_file_system.cpp"
	 "src/platform/win32/opengl/win32_renderer_backend.cpp"

	 "third_party/dear_imgui/imgui.cpp"
	 "third_party/dear_imgui/imgui_draw.cpp"
	 "third_party/dear_imgui/imgui_demo.cpp"
	 "third_party/dear_imgui/imgui_tables.cpp"
	 "third_party/dear_imgui/imgui_widgets.cpp"
	 "third_party/dear_imgui/backends/imgui_impl_opengl3.cpp"
	 "third_party/dear_imgui/backends/imgui_impl_win32.cpp"
	 "third_party/stb_image/stb_image.cpp"
	 "third_party/tinyxml2/tinyxml2.cpp"
  )

add_executable(shader_playground ${SOURCE_FILES})

target_include_directories(shader_playground PUBLIC "src/")
target_include_directories(shader_playground PUBLIC "third_party/")
target_include_directories(shader_playground PUBLIC "third_party/dear_imgui/")
target_include_directories(shader_playground PUBLIC "third_party/dear_imgui/backends")
target_include_directories(shader_playground PUBLIC "third_party/stb_image")





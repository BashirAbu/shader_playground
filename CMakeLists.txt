cmake_minimum_required(VERSION 3.0.0)

project(shader_playground VERSION 0.1.0 LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 17)
add_compile_definitions(UNICODE=_UNICODE)
if(WIN32)
	add_compile_definitions(SPG_WINDOWS=1)
	if(MSVC)
		add_compile_options("/utf-8" "/MDd" "/Zi" "/W3" "/wd4127" "/wd4530" "/wd4459" "/wd5105" "/wd4100" "/wd4996")
		if(CMAKE_BUILD_TYPE MATCHES  "Debug")
			add_compile_definitions(SOG_DEBUG=1)
			add_compile_options("/Od") 
		endif()
	endif()
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/cmake_files/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/cmake_files/bin)


set (SOURCE_FILES "src/unity_build.cpp")

add_executable(shader_playground ${SOURCE_FILES})

target_include_directories(shader_playground PUBLIC ".")


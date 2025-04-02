cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11
project(prisma)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMAND ON)

# Dependencies
set(RAYLIB_VERSION 5.5) # [2:54 2-4-25] (jas31415) this latest version throws a deprecation warning due to using cmake 3.5
						# 						   i recommend just fixing it manually for now
find_package(raylib ${RAYLIB_VERSION} QUIET)
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
	include(FetchContent)
	FetchContent_Declare(
		raylib
		DOWNLOAD_EXTRACT_TIMESTAMP OFF
		URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
	)
	FetchContent_GetProperties(raylib)
	if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
		set(FETCHCONTENT_QUIET NO)
		FetchContent_MakeAvailable(raylib)
		set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # Don't build the supplied examples
	endif()
endif()

# Our Project

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} raylib)

# [22:35 1-4-25] (jas31415) i don't see prisma needing a web config, but i'll leave it commented just in case XD
# Web Configuration
# if (${PLATFORM} STREQUAL "Web")
# 	set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html") # Tell Emscripten to build a .html file
# 	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -s GL_ENABLE_GET_PROC_ADDRESS=1")
# endif()

# [22:41 1-4-25] (jas31415) don't crucify me for calling them frameworks, i'm just quoting the example 'u.u
# Checks if OSX is used and links appropriate frameworks (Only required on MacOS)
if (APPLE)
	target_link_libraries(${PROJECT_NAME} "-framework IOKit")
	target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
	target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()
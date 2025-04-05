cmake_minimum_required(VERSION 3.10)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
PRIVATE
	main.cpp
	editor.cpp
	settings.cpp
	macros.cpp
	)
target_link_libraries(${PROJECT_NAME} PRIVATE vendored)
cmake_minimum_required(VERSION 3.10)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
PRIVATE
	main.cpp
	editorproject.cpp
	settings.cpp
	theme.cpp
	renderitem.cpp
	)
target_link_libraries(${PROJECT_NAME} PRIVATE vendored)
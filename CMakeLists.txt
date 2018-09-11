cmake_minimum_required (VERSION 3.9) 

## Include global dependencies ##
## End of include global dependencies ##

find_package(OpenGL)

## Include libraries ## 
	include_directories ("${PROJECT_BINARY_DIR}/../bsc_modules/glfw/include")
	include_directories ("${PROJECT_BINARY_DIR}/../bsc_modules/glew/include")
	include_directories ("${PROJECT_BINARY_DIR}/../include") 
## End of include libraries ## 

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE}) 

if (MSVC) 
	set(EXECUTABLE_OUTPUT_PATH bin/) 
endif (MSVC) 

## Find libs ##
	## set(CMAKE_PREFIX_PATH ./bsc_modules/glfw/lib-mingw-w64)
	find_library(GLFW glfw3 HINTS ./bsc_modules/glfw/lib-mingw-w64)

	## set(CMAKE_PREFIX_PATH ./bsc_modules/glew/lib/Release/x64)
	find_library(GLEW glew32 HINTS ./bsc_modules/glew/lib/Release/x64)
	find_library(GLEWs glew32s HINTS ./bsc_modules/glew/lib/Release/x64)
## End of finding libs ##

## Add executables ##
	add_subdirectory (src) 
	add_subdirectory (test) 
## End of adding executables ##

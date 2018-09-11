project(nuklear_opengl4) 

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE}) 

## Add source files ## 
	file (GLOB_RECURSE source_files ./*) 
## End of adding source files ## 

## Remove main.c files of modules ## 
## End of removing main.c files of modules ## 

## Add executables ## 
	add_executable (nuklear_opengl4 ${source_files})
	target_link_libraries(nuklear_opengl4 ${GLFW} ${GLEW} ${GLEWs} ${OPENGL_gl_LIBRARY})
## End of adding executables ##

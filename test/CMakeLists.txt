project(test_nuklear_opengl4) 

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE}) 

## Add source files ## 
	file (GLOB_RECURSE testing_files ./*) 
	file (GLOB_RECURSE testing_source_files ../src/*) 
## End of adding source files ## 

## Remove main.c files of modules ## 
	FOREACH(item ${testing_source_files}) 
		IF(${item} MATCHES "main.c") 
			LIST(REMOVE_ITEM testing_source_files ${item}) 
		ENDIF(${item} MATCHES "main.c") 
	ENDFOREACH(item) 
## End of removing main.c files of modules ## 

## Add executables ## 
	add_executable (test_nuklear_opengl4 ${testing_files} ${testing_source_files}) 
## End of adding executables ##
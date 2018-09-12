/* nuklear - 1.32.0 - public domain */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <math.h>
#include <limits.h>
#include <time.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_IMPLEMENTATION
#define NK_GLFW_GL3_IMPLEMENTATION

#include "nuklear.h"
#include "nuklear_glfw_gl3.h"
#include "nuklear_init.h"

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800

#define MAX_VERTEX_BUFFER 512 * 1024
#define MAX_ELEMENT_BUFFER 128 * 1024

/* ===============================================================
 *
 *                          EXAMPLE
 *
 * ===============================================================*/
/* This are some code examples to provide a small overview of what can be
 * done with this library. To try out an example uncomment the defines */
/*#define INCLUDE_ALL */
/*#define INCLUDE_STYLE */
/*#define INCLUDE_CALCULATOR */
/*#define INCLUDE_OVERVIEW */
/*#define INCLUDE_NODE_EDITOR */

#ifdef INCLUDE_ALL
	// #define INCLUDE_STYLE
	// #define INCLUDE_CALCULATOR
	// #define INCLUDE_OVERVIEW
	// #define INCLUDE_NODE_EDITOR
#endif

#ifdef INCLUDE_STYLE
	#include "style.h"
#endif
#ifdef INCLUDE_CALCULATOR
	#include "calculator.h"
#endif
#ifdef INCLUDE_OVERVIEW
	#include "overview.h"
#endif
#ifdef INCLUDE_NODE_EDITOR
	#include "node_editor.h"
#endif

/* ===============================================================
 *
 *                          DEMO
 *
 * ===============================================================*/
static void error_callback(int e, const char *d)
{printf("Error %d: %s\n", e, d);}

int main(void)
{
		/* Platform */
		static GLFWwindow *win;
		int width = 0, height = 0;

		/* GLFW */
		glfwSetErrorCallback(error_callback);
		if (!glfwInit()) {
				fprintf(stdout, "[GFLW] failed to init!\n");
				exit(1);
		}
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
		win = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Demo", NULL, NULL);
		glfwMakeContextCurrent(win);
		glfwGetWindowSize(win, &width, &height);

		/* OpenGL */
		glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
		glewExperimental = 1;
		if (glewInit() != GLEW_OK) {
				fprintf(stderr, "Failed to setup GLEW\n");
				exit(1);
		}

		nuklear_init(win);
		
		while (!glfwWindowShouldClose(win))
		{
				/* Input */
				glfwPollEvents();
				nk_glfw3_new_frame();

				/* GUI */
				nuklear_draw();
	
				/* -------------- EXAMPLES ---------------- */

				// #ifdef INCLUDE_CALCULATOR
				// 	calculator(ctx);
				// #endif
				// #ifdef INCLUDE_OVERVIEW
				// 	overview(ctx);
				// #endif
				// #ifdef INCLUDE_NODE_EDITOR
				// 	node_editor(ctx);
				// #endif
				/* ----------------------------------------- */

				/* Draw */
				glfwGetWindowSize(win, &width, &height);
				glViewport(0, 0, width, height);
				glClear(GL_COLOR_BUFFER_BIT);
				glClearColor(bg.r, bg.g, bg.b, bg.a);
				/* IMPORTANT: `nk_glfw_render` modifies some global OpenGL state
				 * with blending, scissor, face culling, depth test and viewport and
				 * defaults everything back into a default state.
				 * Make sure to either a.) save and restore or b.) reset your own state after
				 * rendering the UI. */
				nk_glfw3_render(NK_ANTI_ALIASING_ON, MAX_VERTEX_BUFFER, MAX_ELEMENT_BUFFER);
				glfwSwapBuffers(win);
		}
		nk_glfw3_shutdown();
		glfwTerminate();
		return 0;
}


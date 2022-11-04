//// Include standard headers
//#include <stdio.h>
//#include <stdlib.h>
//#pragma region
//
//#pragma endregion
//// Include GLEW. Always include it before gl.h and glfw3.h, since it's a bit magic.
//#include <GL/glew.h>
//
//// Include GLFW 使用GLFW来处理窗口和键盘消息
//#include <GLFW/glfw3.h>
//
//// Include GLM GLM是个3D数学库
//#include <glm/glm.hpp>
//
//// 加载顶点和片段着色器的相应函数的头文件
//#include <shader.hpp>
//
//using namespace glm;
//
//#pragma region
//
//
//// An array of 3 vectors which represents 3 vertices
//static const GLfloat g_vertex_buffer_data[] = {
//	//一个三角形的三个顶点
//   -1.0f, -1.0f, 0.0f,
//   1.0f, -1.0f, 0.0f,
//   0.0f,  1.0f, 0.0f,
//};
//
//#pragma endregion
//
//int main()
//{
//	// Initialise GLFW 
//	// 初始化GLFW
//#pragma region
//	if (!glfwInit())
//	{
//		fprintf(stderr, "Failed to initialize GLFW\n");
//		return -1;
//	}
//#pragma endregion
//
//	// Initialise window
//	// 初始化并生成一个窗口
//#pragma region
//	//设置OpenGL版本
//	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3 这个是大版本
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //这个是小版本
//
//	// Open a window and create its OpenGL context
//	// 打开窗口并创建文本
//	GLFWwindow* window;
//	window = glfwCreateWindow(1024, 768, "my 复健 test", NULL, NULL);
//
//	if (window == NULL)
//	{
//		fprintf(stderr, "Failed to open GLFW window\n");
//		glfwTerminate();
//		return -1;
//	}
//
//	// Initialize GLEW
//	glfwMakeContextCurrent(window);
//	glewExperimental = true; // Needed in core profile
//	if (glewInit() != GLEW_OK) {
//		fprintf(stderr, "Failed to initialize GLEW\n");
//		return -1;
//	}
//#pragma endregion
//
//	// Ensure we can capture the escape key being pressed below
//	// 可以按键
//	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
//	// Dark blue background
//	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
//
//
//	// 创建一个VAO，必须在窗口创建后紧接着完成
//#pragma region
//	//创建一个VAO并将它设为当前对象
//	GLuint VertexArrayID;
//	glGenVertexArrays(1, &VertexArrayID);
//	glBindVertexArray(VertexArrayID);
//
//	// Create and compile our GLSL program from the shaders
//	GLuint programID = LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");
//
//	//通过缓冲把三角形传给OpenGL，这步操作仅需执行一次。
//#pragma region
//
//	// This will identify our vertex buffer
//	GLuint vertexbuffer;//三角形的顶点缓冲
//
//	// Generate 1 buffer, put the resulting identifier in vertexbuffer
//	// 生成1个缓冲区，将结果标识符放在vertexbuffer中
//	glGenBuffers(1, &vertexbuffer);
//
//	// The following commands will talk about our 'vertexbuffer' buffer
//	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//
//	// Give our vertices to OpenGL.
//	// 将顶点数据给OpenGL
//	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
//
//#pragma endregion
//
//#pragma endregion
//
//
//
//	do {
//		// Clear the screen
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		// Use our shader
//		glUseProgram(programID);
//
//		// 1rst attribute buffer : vertices
//		glEnableVertexAttribArray(0);
//		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//		glVertexAttribPointer(
//			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
//			3,                  // size
//			GL_FLOAT,           // type
//			GL_FALSE,           // normalized?
//			0,                  // stride
//			(void*)0            // array buffer offset
//		);
//		// Draw the triangle !
//		glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
//		glDisableVertexAttribArray(0);
//
//		// Swap buffers
//		// 交换缓冲（其实就是画出来）
//		glfwSwapBuffers(window);
//
//	} // Check if the ESC key was pressed or the window was closed
//	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
//		glfwWindowShouldClose(window) == 0);
//
//
//	return 0;
//}
//#pragma comment(lib,"glew32.lib")
#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>

#include <GLFW/glfw3.h>
GLFWwindow* window;

#include <glm/glm.hpp>
using namespace glm;

int main(void)
{
	// Initialise GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(1024, 768, "Playground", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	do {
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw nothing, see you in tutorial 2 !

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}


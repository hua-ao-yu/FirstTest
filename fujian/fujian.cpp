//// Include standard headers
//#include <stdio.h>
//#include <stdlib.h>
//#pragma region
//
//#pragma endregion
//// Include GLEW. Always include it before gl.h and glfw3.h, since it's a bit magic.
//#include <GL/glew.h>
//
//// Include GLFW ʹ��GLFW�������ںͼ�����Ϣ
//#include <GLFW/glfw3.h>
//
//// Include GLM GLM�Ǹ�3D��ѧ��
//#include <glm/glm.hpp>
//
//// ���ض����Ƭ����ɫ������Ӧ������ͷ�ļ�
//#include <shader.hpp>
//
//using namespace glm;
//
//#pragma region
//
//
//// An array of 3 vectors which represents 3 vertices
//static const GLfloat g_vertex_buffer_data[] = {
//	//һ�������ε���������
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
//	// ��ʼ��GLFW
//#pragma region
//	if (!glfwInit())
//	{
//		fprintf(stderr, "Failed to initialize GLFW\n");
//		return -1;
//	}
//#pragma endregion
//
//	// Initialise window
//	// ��ʼ��������һ������
//#pragma region
//	//����OpenGL�汾
//	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3 ����Ǵ�汾
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //�����С�汾
//
//	// Open a window and create its OpenGL context
//	// �򿪴��ڲ������ı�
//	GLFWwindow* window;
//	window = glfwCreateWindow(1024, 768, "my ���� test", NULL, NULL);
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
//	// ���԰���
//	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
//	// Dark blue background
//	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
//
//
//	// ����һ��VAO�������ڴ��ڴ�������������
//#pragma region
//	//����һ��VAO��������Ϊ��ǰ����
//	GLuint VertexArrayID;
//	glGenVertexArrays(1, &VertexArrayID);
//	glBindVertexArray(VertexArrayID);
//
//	// Create and compile our GLSL program from the shaders
//	GLuint programID = LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");
//
//	//ͨ������������δ���OpenGL���ⲽ��������ִ��һ�Ρ�
//#pragma region
//
//	// This will identify our vertex buffer
//	GLuint vertexbuffer;//�����εĶ��㻺��
//
//	// Generate 1 buffer, put the resulting identifier in vertexbuffer
//	// ����1�����������������ʶ������vertexbuffer��
//	glGenBuffers(1, &vertexbuffer);
//
//	// The following commands will talk about our 'vertexbuffer' buffer
//	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//
//	// Give our vertices to OpenGL.
//	// ���������ݸ�OpenGL
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
//		// �������壨��ʵ���ǻ�������
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


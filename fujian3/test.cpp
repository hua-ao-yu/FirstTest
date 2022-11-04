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
//GLFWwindow* window;
//
//// Include GLM GLM是个3D数学库
//#include <glm/glm.hpp>
//#include <glm/gtx/transform.hpp> // after <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp> 
//using namespace glm;
//
//// 加载顶点和片段着色器的相应函数的头文件
//#include "shader.hpp"
//
//#pragma region
//
//// An array of 3 vectors which represents 3 vertices
//// 每个三角面元的坐标
//static const GLfloat g_vertex_buffer_data[] = {
//	-1.0f,-1.0f,-1.0f, // triangle 1 : begin
//	-1.0f,-1.0f, 1.0f,
//	-1.0f, 1.0f, 1.0f, // triangle 1 : end
//	1.0f, 1.0f,-1.0f, // triangle 2 : begin
//	-1.0f,-1.0f,-1.0f,
//	-1.0f, 1.0f,-1.0f, // triangle 2 : end
//	1.0f,-1.0f, 1.0f,
//	-1.0f,-1.0f,-1.0f,
//	1.0f,-1.0f,-1.0f,
//	1.0f, 1.0f,-1.0f,
//	1.0f,-1.0f,-1.0f,
//	-1.0f,-1.0f,-1.0f,
//	-1.0f,-1.0f,-1.0f,
//	-1.0f, 1.0f, 1.0f,
//	-1.0f, 1.0f,-1.0f,
//	1.0f,-1.0f, 1.0f,
//	-1.0f,-1.0f, 1.0f,
//	-1.0f,-1.0f,-1.0f,
//	-1.0f, 1.0f, 1.0f,
//	-1.0f,-1.0f, 1.0f,
//	1.0f,-1.0f, 1.0f,
//	1.0f, 1.0f, 1.0f,
//	1.0f,-1.0f,-1.0f,
//	1.0f, 1.0f,-1.0f,
//	1.0f,-1.0f,-1.0f,
//	1.0f, 1.0f, 1.0f,
//	1.0f,-1.0f, 1.0f,
//	1.0f, 1.0f, 1.0f,
//	1.0f, 1.0f,-1.0f,
//	-1.0f, 1.0f,-1.0f,
//	1.0f, 1.0f, 1.0f,
//	-1.0f, 1.0f,-1.0f,
//	-1.0f, 1.0f, 1.0f,
//	1.0f, 1.0f, 1.0f,
//	-1.0f, 1.0f, 1.0f,
//	1.0f,-1.0f, 1.0f
//};
//
//// 增加颜色
//static const GLfloat g_color_buffer_data[] = {
//	0.583f,  0.771f,  0.014f,
//	0.609f,  0.115f,  0.436f,
//	0.327f,  0.483f,  0.844f,
//	0.822f,  0.569f,  0.201f,
//	0.435f,  0.602f,  0.223f,
//	0.310f,  0.747f,  0.185f,
//	0.597f,  0.770f,  0.761f,
//	0.559f,  0.436f,  0.730f,
//	0.359f,  0.583f,  0.152f,
//	0.483f,  0.596f,  0.789f,
//	0.559f,  0.861f,  0.639f,
//	0.195f,  0.548f,  0.859f,
//	0.014f,  0.184f,  0.576f,
//	0.771f,  0.328f,  0.970f,
//	0.406f,  0.615f,  0.116f,
//	0.676f,  0.977f,  0.133f,
//	0.971f,  0.572f,  0.833f,
//	0.140f,  0.616f,  0.489f,
//	0.997f,  0.513f,  0.064f,
//	0.945f,  0.719f,  0.592f,
//	0.543f,  0.021f,  0.978f,
//	0.279f,  0.317f,  0.505f,
//	0.167f,  0.620f,  0.077f,
//	0.347f,  0.857f,  0.137f,
//	0.055f,  0.953f,  0.042f,
//	0.714f,  0.505f,  0.345f,
//	0.783f,  0.290f,  0.734f,
//	0.722f,  0.645f,  0.174f,
//	0.302f,  0.455f,  0.848f,
//	0.225f,  0.587f,  0.040f,
//	0.517f,  0.713f,  0.338f,
//	0.053f,  0.959f,  0.120f,
//	0.393f,  0.621f,  0.362f,
//	0.673f,  0.211f,  0.457f,
//	0.820f,  0.883f,  0.371f,
//	0.982f,  0.099f,  0.879f
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
//		getchar();
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
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	// Open a window and create its OpenGL context
//	// 打开窗口并创建文本
//	
//	window = glfwCreateWindow(1024, 768, "my  test", NULL, NULL);
//
//	if (window == NULL)
//	{
//		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
//		getchar();
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//
//	// Initialize GLEW
//	glewExperimental = true; // Needed in core profile
//	if (glewInit() != GLEW_OK) {
//		fprintf(stderr, "Failed to initialize GLEW\n");
//		getchar();
//		glfwTerminate();
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
//	// 施加颜色（这部分必须和上面分开）
//	GLuint colorbuffer;
//	glGenBuffers(1, &colorbuffer);
//	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);
//
//#pragma endregion
//
//#pragma endregion
//
//	//矩阵变换
//#pragma region
//	
//	//第一步：创建模型观察投影（MVP）矩阵。任何要渲染的模型都要做这一步。
//#pragma region
//	// Projection matrix : 45?Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
//	// 创建投影矩阵
//	glm::mat4 Projection = glm::perspective(
//		glm::radians(45.0f), //这个变量可以控制镜头的远近（30近，90远）
//		4.0f / 3.0f, //宽高比，这个变量确定的是窗户的大小
//		0.1f, // 近剪切面。保持尽可能大，否则就会出现精度问题
//		100.0f  // 剪切面。保持越少越好。
//	);
//	// Or, for an ortho camera :
//	//glm::mat4 Projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f); // In world coordinates
//
//	// Camera matrix
//	// 摄像机的参数
//	glm::mat4 View = glm::lookAt(
//		glm::vec3(4, 3, 3), // Camera is at (4,3,3), in World Space 这个是摄像头的位置 （摄像机位置）
//		glm::vec3(0, 0, 0), // and looks at the origin 摄像机方向 （目标位置）
//		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down) 右轴 （表示世界空间上的上方向向量的向量）
//	);
//
//	// Model matrix : an identity matrix (model will be at the origin)
//	// 模型矩阵:单位矩阵(模型在原点)
//	glm::mat4 Model = glm::mat4(1.0f);
//
//	// Our ModelViewProjection : multiplication of our 3 matrices
//	glm::mat4 MVP = Projection * View * Model; // Remember, matrix multiplication is the other way around
//#pragma endregion
//
//	//第二步：把MVP传给GLSL
//	// Get a handle for our "MVP" uniform
//	GLuint MatrixID = glGetUniformLocation(programID, "MVP");
//	
//	//第三部：在while循环里
//	// Send our transformation to the currently bound shader, 
//	// in the "MVP" uniform
//	//glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
//
//#pragma endregion
//
//	do {
//		// Clear the screen
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		// Use our shader
//		glUseProgram(programID);
//
//		// Send our transformation to the currently bound shader, 
//		// in the "MVP" uniform
//		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
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
//		glEnableVertexAttribArray(1);
//		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
//		glVertexAttribPointer(
//			1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
//			3,                                // size
//			GL_FLOAT,                         // type
//			GL_FALSE,                         // normalized?
//			0,                                // stride
//			(void*)0                          // array buffer offset
//		);
//
//
//		glDrawArrays(GL_TRIANGLES, 0, 12*3); // Starting from vertex 0; 3 vertices total -> 1 triangle
//		glDisableVertexAttribArray(0);
//		glDisableVertexAttribArray(1);
//
//		// Swap buffers
//		// 交换缓冲（其实就是画出来）
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//
//	} // Check if the ESC key was pressed or the window was closed
//	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
//		glfwWindowShouldClose(window) == 0);
//
//	glDeleteBuffers(1, &vertexbuffer);
//	glDeleteVertexArrays(1, &VertexArrayID);
//	glDeleteProgram(programID);
//
//	// Close OpenGL window and terminate GLFW
//	glfwTerminate();
//
//	return 0;
//}
//
//

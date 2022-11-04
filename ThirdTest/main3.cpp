#include <glad/glad.h>//这个一定要在上面
#include <GLFW/glfw3.h>//这个在glad的下面
#include <iostream>
using namespace std;
/*******************************函数声明*******************************/
const char *vertexShaderSource = "#version 330 core\n"
"layout(location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"gl_Position = vec4(aPos.x,aPos.y,aPos.z,1.0);\n"
"}\0";
const char *fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"FragColor = vec4(1.0f,0.5f,0.2f,1.0f);\n"
"}\0";

const char *fragmentShader2Source = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"FragColor = vec4(1.0f,1.0f,0.0f,1.0f);\n"
"}\0";
void processInput(GLFWwindow *window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
/*******************************声明结束*******************************/
int main()
{
	/********************************定义顶点数据**************************/
	//float vertices[] = {
	//	-0.5f,-0.5f,0.0f,
	//	0.5f,-0.5f,0.0f,
	//	0.0f,0.5f,0.0f,
	//};
	float vertices[] = {
		//中间的菱形
		0.0f,0.5f,0.0f,
		0.5f,0.0f,0.0f,
		0.0f,-0.5f,0.0f,
		-0.5f,0.0f,0.0f,
		//第一个三角形 右下
		1.0f,-0.5f,0.0f,
		0.5f,-1.0f,0.0f,
		1.0f,-1.0f,0.0f,
		//第二个三角形 左上
		-0.5f,1.0f,0.0f,
		-1.0f,0.5f,0.0f,
		-1.0f,1.0f,0.0f,
		//第三个三角形 左下
		-1.0f,-0.5f,0.0f,
		-1.0f,-1.0f,0.0f,
		-0.5f,-1.0f,0.0f,
		//第四个三角形 右上
		1.0f,1.0f,0.0f,
		1.0f,0.5f,0.0f,
		0.5f,1.0f,0.0f
	};

	unsigned int indices[] = 
	{//EBO用到的索引值
		// 注意索引从0开始! 
		// 此例的索引(0,1,2,3)就是顶点数组vertices的下标，
		// 这样可以由下标代表顶点组合成矩形
		0, 1, 3, // 第一个三角形
		1, 2, 3  // 第二个三角形
	};

	/********************************顶点数据结束**************************/

	glfwInit();//初始化
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//大版本为3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//小版本为3，所以版本为3.3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//核心模式
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window！！" << std::endl;
		glfwTerminate();
		return -1;
	}
	//GLFW将窗口的上下文设置为当前线程的上下文
	glfwMakeContextCurrent(window);
	//注册回调函数
	glfwSetFramebufferSizeCallback(window,framebuffer_size_callback); //使窗口可以拖拽变形
	//GLAD
	//glad：加载所有OpenGL函数指针
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {//连接相关接口，不需要改变
		std::cout << "Fail to intialize GLAD！！" << std::endl;
		return -1;
	}//有窗口了


	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);//线框模式

	/***********************创建顶点着色器和片段着色器***********************/
	//创建和编译着色器程序
	/********顶点着色器********/
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	//检查编译错误
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);//访问顶点着色器状态，并写在success里
	if (!success)
	{//没有编译成功
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);//如果编译错误的话将错误信息放在infoLog
		cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
	}
	/********片段着色器1********/
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	//检查编译错误
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{//没有编译成功
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << endl;
	}
	/********片段着色器2********/
	unsigned int fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader2, 1, &fragmentShader2Source, NULL);
	glCompileShader(fragmentShader2);
	//检查编译错误
	glGetShaderiv(fragmentShader2, GL_COMPILE_STATUS, &success);
	if (!success)
	{//没有编译成功
		glGetShaderInfoLog(fragmentShader2, 512, NULL, infoLog);
		cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << endl;
	}
	/********着色器程序********/
	//着色器程序1 （将顶点着色器和片段着色器串起来）
	unsigned int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	//着色器程序2 （将顶点着色器和片段着色器串起来）
	unsigned int shaderProgram2 = glCreateProgram();
	glAttachShader(shaderProgram2, vertexShader);//顶点着色器不变
	glAttachShader(shaderProgram2, fragmentShader2);//片段着色器换了
	glLinkProgram(shaderProgram2);

	//链接错误检查
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success)
	{//没有编译成功
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << endl;
	}
	glGetProgramiv(shaderProgram2, GL_LINK_STATUS, &success);
	if (!success)
	{//没有编译成功
		glGetProgramInfoLog(shaderProgram2, 512, NULL, infoLog);
		cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << endl;
	}
	glDeleteShader(vertexShader);//已经形成着色器程序这两个就没用了
	glDeleteShader(fragmentShader);
	glDeleteShader(fragmentShader2);
	/***********************顶点着色器和片段着色器创建结束*******************/

	/**********************************加载VAO和VBO************************/
	unsigned int VAOs[2], VBOs[2], EBO;
	//创建VAO和VBO对象并赋予ID
	glGenVertexArrays(2, VAOs);//创建2个VAO对象
	glGenBuffers(2, VBOs);//创建2个VBO对象
	glGenBuffers(1, &EBO);//创建一个EBO对象
	/*第一个绑定VAO和VBO对象*/
	glBindVertexArray(VAOs[0]);//绑定VAO，不需要指定VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);//以ARRAY_BUFFER的形式绑定VBO
	//为当前绑定到target的缓冲区对象创建一个新的数据存储
	//如果data不是NULL，则使用来自此指针的数据初始化数据存储
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices[0], GL_STATIC_DRAW);

	//告知shader如何解析缓冲里的属性值
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);//第0项索引 3个 float格式 是否需要标准化（false为否） 步长（三个顶点坐标就是3个float） 偏移量
	//开启VAO管理的第一个属性值
	glEnableVertexAttribArray(0);//设置了第0个，所以开启了第0个，需要对应上

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);//绑定EBO对象
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);//用缓冲数据填充

	/*第二个绑定VAO和VBO对象*/
	glBindVertexArray(VAOs[1]);//绑定VAO，不需要指定VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);//以ARRAY_BUFFER的形式绑定VBO
	//为当前绑定到target的缓冲区对象创建一个新的数据存储
	//如果data不是NULL，则使用来自此指针的数据初始化数据存储
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) , &vertices[0], GL_STATIC_DRAW);

	//告知shader如何解析缓冲里的属性值
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);//第0项索引 3个 float格式 是否需要标准化（false为否） 步长（三个顶点坐标就是3个float） 偏移量
	//开启VAO管理的第一个属性值
	glEnableVertexAttribArray(0);//设置了第0个，所以开启了第0个，需要对应上


	glBindBuffer(GL_ARRAY_BUFFER, 0);//用完以后给VBO解绑	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);//解除绑定EBO对象
	glBindVertexArray(0);//给VAO解绑，VAO中会记录EBO的数据，所以需要最后解绑
	/**********************************加载完毕********************************/
	cout << sizeof(vertices);
	//渲染循环
	while (!glfwWindowShouldClose(window))
	{//一个循环为一帧
		processInput(window);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);//状态设置，设置某一种颜色
		glClear(GL_COLOR_BUFFER_BIT);//状态使用，使用刚才设置的颜色
		//glfw:交换缓冲区和轮询IO事件（按键按下/释放、鼠标移动等）
		glUseProgram(shaderProgram);//选择流水线
		glBindVertexArray(VAOs[0]);//绑定VAO，告诉材料怎么布局
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glDrawArrays(GL_TRIANGLES, 4, 6);//从第0个开始拿3个点的数据画三角形

		glUseProgram(shaderProgram2);//选择流水线
		glBindVertexArray(VAOs[1]);//绑定VAO，告诉材料怎么布局
		glDrawArrays(GL_TRIANGLES, 10, 6);//从第0个开始拿3个点的数据画三角形

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, indices);
		glfwSwapBuffers(window);//绘制图像
		glfwPollEvents();//一些事件，比如说关掉窗口
	}
	//glfw:回收前面分配的GLFW先关资源
	glfwTerminate();
	glDeleteVertexArrays(1,VAOs);
	glDeleteBuffers(1, VBOs);
	glDeleteBuffers(1, &EBO);
	glDeleteProgram(shaderProgram);
	glDeleteProgram(shaderProgram2);
	return 0;

}

void processInput(GLFWwindow *window) {
	//此函数用于查看是否按下ESC键，按下的话就关闭
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)//release就是弹起来
		glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window,int width,int height) {//使窗口可以拖拽变形
	glViewport(0, 0, width, height);
}

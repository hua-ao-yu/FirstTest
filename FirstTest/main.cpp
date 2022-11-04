#include <glad/glad.h>//这个一定要在上面
#include <GLFW/glfw3.h>//这个在glad的下面
#include <iostream>
/*******************************函数声明*******************************/
void processInput(GLFWwindow *window);
/*******************************声明结束*******************************/
int main()
{
	glfwInit();//初始化
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);//大版本为3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);//小版本为3，所以版本为3.3
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);//核心模式
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
#endif
	GLFWwindow* window = glfwCreateWindow(800,600,"LearnOpenGL",NULL,NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window！！" << std::endl;
		glfwTerminate();
		return -1;
	}
	//GLFW将窗口的上下文设置为当前线程的上下文
	glfwMakeContextCurrent(window);

	//GLAD
	//glad：加载所有OpenGL函数指针
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {//连接相关接口，不需要改变
		std::cout<<"Fail to intialize GLAD！！"<<std::endl;
			return -1;
	}//有窗口了
	//渲染循环
	while (!glfwWindowShouldClose(window))
	{//一个循环为一帧
		glClearColor(0.2f,0.3f,0.3f,1.0f);//状态设置，设置某一种颜色
		glClear(GL_COLOR_BUFFER_BIT);//状态使用，使用刚才设置的颜色
		//glfw:交换缓冲区和轮询IO事件（按键按下/释放、鼠标移动等）
		processInput(window);
		glfwSwapBuffers(window);
		glfwPollEvents();//一些事件，比如说关掉窗口
	}
	//glfw:回收前面分配的GLFW先关资源
	glfwTerminate();
	return 0;

}

void processInput(GLFWwindow *window) {
	//此函数用于查看是否按下ESC键，按下的话就关闭
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)//release就是弹起来
		glfwSetWindowShouldClose(window,true);
}
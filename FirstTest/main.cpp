#include <glad/glad.h>//���һ��Ҫ������
#include <GLFW/glfw3.h>//�����glad������
#include <iostream>
/*******************************��������*******************************/
void processInput(GLFWwindow *window);
/*******************************��������*******************************/
int main()
{
	glfwInit();//��ʼ��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);//��汾Ϊ3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);//С�汾Ϊ3�����԰汾Ϊ3.3
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);//����ģʽ
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
#endif
	GLFWwindow* window = glfwCreateWindow(800,600,"LearnOpenGL",NULL,NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window����" << std::endl;
		glfwTerminate();
		return -1;
	}
	//GLFW�����ڵ�����������Ϊ��ǰ�̵߳�������
	glfwMakeContextCurrent(window);

	//GLAD
	//glad����������OpenGL����ָ��
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {//������ؽӿڣ�����Ҫ�ı�
		std::cout<<"Fail to intialize GLAD����"<<std::endl;
			return -1;
	}//�д�����
	//��Ⱦѭ��
	while (!glfwWindowShouldClose(window))
	{//һ��ѭ��Ϊһ֡
		glClearColor(0.2f,0.3f,0.3f,1.0f);//״̬���ã�����ĳһ����ɫ
		glClear(GL_COLOR_BUFFER_BIT);//״̬ʹ�ã�ʹ�øղ����õ���ɫ
		//glfw:��������������ѯIO�¼�����������/�ͷš�����ƶ��ȣ�
		processInput(window);
		glfwSwapBuffers(window);
		glfwPollEvents();//һЩ�¼�������˵�ص�����
	}
	//glfw:����ǰ������GLFW�ȹ���Դ
	glfwTerminate();
	return 0;

}

void processInput(GLFWwindow *window) {
	//�˺������ڲ鿴�Ƿ���ESC�������µĻ��͹ر�
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)//release���ǵ�����
		glfwSetWindowShouldClose(window,true);
}
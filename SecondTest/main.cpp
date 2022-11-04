#include <glad/glad.h>//���һ��Ҫ������
#include <GLFW/glfw3.h>//�����glad������
#include <iostream>
using namespace std;
/*******************************��������*******************************/
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
void processInput(GLFWwindow *window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
/*******************************��������*******************************/
int main()
{
	/********************************���嶥������**************************/
	//float vertices[] = {
	//	-0.5f,-0.5f,0.0f,
	//	0.5f,-0.5f,0.0f,
	//	0.0f,0.5f,0.0f,
	//};
	float vertices[] = {
		//�м������
		0.0f,0.5f,0.0f,
		0.5f,0.0f,0.0f,
		0.0f,-0.5f,0.0f,
		-0.5f,0.0f,0.0f,
		//��һ�������� ����
		1.0f,-0.5f,0.0f,
		0.5f,-1.0f,0.0f,
		1.0f,-1.0f,0.0f,
		//�ڶ��������� ����
		-0.5f,1.0f,0.0f,
		-1.0f,0.5f,0.0f,
		-1.0f,1.0f,0.0f,
		//������������ ����
		-1.0f,-0.5f,0.0f,
		-1.0f,-1.0f,0.0f,
		-0.5f,-1.0f,0.0f,
		//���ĸ������� ����
		1.0f,1.0f,0.0f,
		1.0f,0.5f,0.0f,
		0.5f,1.0f,0.0f
	};

	unsigned int indices[] = 
	{//EBO�õ�������ֵ
		// ע��������0��ʼ! 
		// ����������(0,1,2,3)���Ƕ�������vertices���±꣬
		// �����������±��������ϳɾ���
		0, 1, 3, // ��һ��������
		1, 2, 3  // �ڶ���������
	};

	/********************************�������ݽ���**************************/

	glfwInit();//��ʼ��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//��汾Ϊ3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//С�汾Ϊ3�����԰汾Ϊ3.3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//����ģʽ
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window����" << std::endl;
		glfwTerminate();
		return -1;
	}
	//GLFW�����ڵ�����������Ϊ��ǰ�̵߳�������
	glfwMakeContextCurrent(window);
	//ע��ص�����
	glfwSetFramebufferSizeCallback(window,framebuffer_size_callback); //ʹ���ڿ�����ק����
	//GLAD
	//glad����������OpenGL����ָ��
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {//������ؽӿڣ�����Ҫ�ı�
		std::cout << "Fail to intialize GLAD����" << std::endl;
		return -1;
	}//�д�����


	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//�߿�ģʽ

	/***********************����������ɫ����Ƭ����ɫ��***********************/
	//�����ͱ�����ɫ������
	/********������ɫ��********/
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	//���������
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);//���ʶ�����ɫ��״̬����д��success��
	if (!success)
	{//û�б���ɹ�
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);//����������Ļ���������Ϣ����infoLog
		cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
	}
	/********Ƭ����ɫ��********/
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	//���������
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{//û�б���ɹ�
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << endl;
	}
	/********��ɫ������********/
	//��ɫ������ ����������ɫ����Ƭ����ɫ����������
	unsigned int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	//���Ӵ�����
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success)
	{//û�б���ɹ�
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << endl;
	}
	glDeleteShader(vertexShader);//�Ѿ��γ���ɫ��������������û����
	glDeleteShader(fragmentShader);
	/***********************������ɫ����Ƭ����ɫ����������*******************/

	/**********************************����VAO��VBO************************/
	unsigned int VAO, VBO, EBO;
	//����VAO��VBO���󲢸���ID
	glGenVertexArrays(1, &VAO);//����һ��VAO����
	glGenBuffers(1, &VBO);//����һ��VBO����
	glGenBuffers(1, &EBO);//����һ��EBO����
	//��VAO��VBO����
	glBindVertexArray(VAO);//��VAO������Ҫָ��VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);//��ARRAY_BUFFER����ʽ��VBO
	//Ϊ��ǰ�󶨵�target�Ļ��������󴴽�һ���µ����ݴ洢
	//���data����NULL����ʹ�����Դ�ָ������ݳ�ʼ�����ݴ洢
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//��֪shader��ν��������������ֵ
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);//��0������ 3�� float��ʽ �Ƿ���Ҫ��׼����falseΪ�� ���������������������3��float�� ƫ����
	//����VAO����ĵ�һ������ֵ
	glEnableVertexAttribArray(0);//�����˵�0�������Կ����˵�0������Ҫ��Ӧ��

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);//��EBO����
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);//�û����������

	glBindBuffer(GL_ARRAY_BUFFER, 0);//�����Ժ��VBO���	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);//�����EBO����
	glBindVertexArray(0);//��VAO���VAO�л��¼EBO�����ݣ�������Ҫ�����
	/**********************************�������********************************/

	//��Ⱦѭ��
	while (!glfwWindowShouldClose(window))
	{//һ��ѭ��Ϊһ֡
		processInput(window);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);//״̬���ã�����ĳһ����ɫ
		glClear(GL_COLOR_BUFFER_BIT);//״̬ʹ�ã�ʹ�øղ����õ���ɫ
		//glfw:��������������ѯIO�¼�����������/�ͷš�����ƶ��ȣ�
		glUseProgram(shaderProgram);//ѡ����ˮ��
		glBindVertexArray(VAO);//��VAO�����߲�����ô����
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glDrawArrays(GL_TRIANGLES, 4, 12);//�ӵ�0����ʼ��3��������ݻ�������
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, indices);
		glfwSwapBuffers(window);//����ͼ��
		glfwPollEvents();//һЩ�¼�������˵�ص�����
	}
	//glfw:����ǰ������GLFW�ȹ���Դ
	glfwTerminate();
	glDeleteVertexArrays(1,&VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteProgram(shaderProgram);
	return 0;

}

void processInput(GLFWwindow *window) {
	//�˺������ڲ鿴�Ƿ���ESC�������µĻ��͹ر�
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)//release���ǵ�����
		glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window,int width,int height) {//ʹ���ڿ�����ק����
	glViewport(0, 0, width, height);
}

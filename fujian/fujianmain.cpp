//#include <glad/glad.h>//���һ��Ҫ������
//#include <GLFW/glfw3.h>//�����glad������
//#include <cmath>
//#include <iostream>
//using namespace std;
//#define pi acos(-1)
////����������˲�ͬ��ɫ�Ľ���
///*******************************��������*******************************/
//const char *vertexShaderSource = "#version 330 core\n"
//"layout(location = 0) in vec3 aPos;\n"//������ɫ���ĵ�һ������Ϊ��ά���꣬��Ҫvec3
//"layout(location = 1) in vec3 aColor;\n"//������ɫ���ĵڶ�������Ϊ��ά���꣬��Ҫvec3
//"out vec3 ourColor;\n"
//"void main()\n"
//"{\n"
//"gl_Position = vec4(aPos.x,aPos.y,aPos.z,1.0);\n"
//"ourColor=aColor;\n"
////"vertexColor = vec4(0.5, 0.0, 0.0, 1.0);\n"
//"}\0";
//const char *fragmentShaderSource = "#version 330 core\n"
//"out vec4 FragColor1;\n"
//"uniform vec4 ourColor1;\n"
//"void main()\n"
//"{\n"
//"FragColor1 = ourColor1;\n"//vec4(1.0f,0.5f,0.2f,1.0f);\n"
//"}\0";//�����ֵ�Ӷ�����ɫ�����͵�Ƭ����ɫ��
//const char *fragmentShader2Source = "#version 330 core\n"
//"out vec4 FragColor2;\n"
//"in vec3 ourColor;\n"//�����涥����ɫ����ourColor����
//"void main()\n"
//"{\n"
//"FragColor2 = vec4(ourColor, 1.0f);\n"
//"}\0";
//void processInput(GLFWwindow *window);
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
///*******************************��������*******************************/
//int main()
//{
//	/********************************���嶥������**************************/
//	//float vertices[] = {
//	//	-0.5f,-0.5f,0.0f,
//	//	0.5f,-0.5f,0.0f,
//	//	0.0f,0.5f,0.0f,
//	//};
//	float vertices[] = {
//		//�м������
//		0.0f,0.5f,0.0f,
//		0.5f,0.0f,0.0f,
//		0.0f,-0.5f,0.0f,
//		-0.5f,0.0f,0.0f,
//		//��һ�������� ����
//		1.0f,-0.5f,0.0f,
//		0.5f,-1.0f,0.0f,
//		1.0f,-1.0f,0.0f,
//		//�ڶ��������� ����
//		-0.5f,1.0f,0.0f,
//		-1.0f,0.5f,0.0f,
//		-1.0f,1.0f,0.0f,
//		//������������ ����
//		-1.0f,-0.5f,0.0f,
//		-1.0f,-1.0f,0.0f,
//		-0.5f,-1.0f,0.0f,
//		//���ĸ������� ����
//		1.0f,1.0f,0.0f,
//		1.0f,0.5f,0.0f,
//		0.5f,1.0f,0.0f,
//		//����������� �� ������+��ɫ
//		-1.0f,0.5f,0.0f,1.0f,0.0f,0.0f,
//		-0.5f,0.0f,0.0f,0.0f,1.0f,0.0f,
//		-1.0f,-0.5f,0.0f,0.0f,0.0f,1.0f
//	};
//	float jianbian[] = {
//		//����������� �� ������+��ɫ
//		-1.0f,0.5f,0.0f,1.0f,0.0f,0.0f,
//		-0.5f,0.0f,0.0f,0.0f,1.0f,0.0f,
//		-1.0f,-0.5f,0.0f,0.0f,0.0f,1.0f
//	};
//
//	unsigned int indices[] =
//	{//EBO�õ�������ֵ
//		// ע��������0��ʼ! 
//		// ����������(0,1,2,3)���Ƕ�������vertices���±꣬
//		// �����������±��������ϳɾ���
//		0, 1, 3, // ��һ��������
//		1, 2, 3  // �ڶ���������
//	};
//
//	/********************************�������ݽ���**************************/
//
//	glfwInit();//��ʼ��
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//��汾Ϊ3
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//С�汾Ϊ3�����԰汾Ϊ3.3
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//����ģʽ
//#ifdef __APPLE__
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif
//	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window����" << std::endl;
//		glfwTerminate();
//		return -1;
//	} 
//	//GLFW�����ڵ�����������Ϊ��ǰ�̵߳�������
//	glfwMakeContextCurrent(window);
//	//ע��ص�����
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); //ʹ���ڿ�����ק����
//	//GLAD
//	//glad����������OpenGL����ָ��
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {//������ؽӿڣ�����Ҫ�ı�
//		std::cout << "Fail to intialize GLAD����" << std::endl;
//		return -1;
//	}//�д�����
//
//
//	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);//�߿�ģʽΪGL_LINE
//
//	/***********************����������ɫ����Ƭ����ɫ��***********************/
//	//�����ͱ�����ɫ������
//	/********������ɫ��********/
//	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	glCompileShader(vertexShader);
//	//���������
//	int success;
//	char infoLog[512];
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);//���ʶ�����ɫ��״̬����д��success��
//	if (!success)
//	{//û�б���ɹ�
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);//����������Ļ���������Ϣ����infoLog
//		cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
//	}
//	/********Ƭ����ɫ��********/
//	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//	glCompileShader(fragmentShader);
//	//���������
//	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{//û�б���ɹ�
//		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//		cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << endl;
//	}
//
//	unsigned int fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader2, 1, &fragmentShader2Source, NULL);
//	glCompileShader(fragmentShader2);
//	//���������
//	glGetShaderiv(fragmentShader2, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{//û�б���ɹ�
//		glGetShaderInfoLog(fragmentShader2, 512, NULL, infoLog);
//		cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << endl;
//	}
//	/********��ɫ������********/
//	//��ɫ������ ����������ɫ����Ƭ����ɫ����������
//	unsigned int shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//	//���Ӵ�����
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	if (!success)
//	{//û�б���ɹ�
//		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//		cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << endl;
//	}
//	unsigned int shaderProgram2 = glCreateProgram();
//	glAttachShader(shaderProgram2, vertexShader);
//	glAttachShader(shaderProgram2, fragmentShader2);
//	glLinkProgram(shaderProgram2);
//	//���Ӵ�����
//	glGetProgramiv(shaderProgram2, GL_LINK_STATUS, &success);
//	if (!success)
//	{//û�б���ɹ�
//		glGetProgramInfoLog(shaderProgram2, 512, NULL, infoLog);
//		cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << endl;
//	}
//	glDeleteShader(fragmentShader2);
//	/***********************������ɫ����Ƭ����ɫ����������*******************/
//
//	/**********************************����VAO��VBO************************/
//	unsigned int VAO[2], VBO[2], EBO;
//	//����VAO��VBO���󲢸���ID
//	glGenVertexArrays(1, &VAO[0]);//����һ��VAO����
//	glGenBuffers(1, &VBO[0]);//����һ��VBO����
//	glGenBuffers(1, &EBO);//����һ��EBO����
//	//��VAO��VBO����
//	glBindVertexArray(VAO[0]);//��VAO������Ҫָ��VBO
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);//��ARRAY_BUFFER����ʽ��VBO
//	//Ϊ��ǰ�󶨵�target�Ļ��������󴴽�һ���µ����ݴ洢
//	//���data����NULL����ʹ�����Դ�ָ������ݳ�ʼ�����ݴ洢
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	//��֪shader��ν��������������ֵ
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);//��0������ 3�� float��ʽ �Ƿ���Ҫ��׼����falseΪ�� ���������������������3��float�� ƫ����
//	//����VAO����ĵ�һ������ֵ
//	glEnableVertexAttribArray(0);//�����˵�0�������Կ����˵�0������Ҫ��Ӧ��
//
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);//��EBO����
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);//�û����������
//
//	//glBindBuffer(GL_ARRAY_BUFFER, 0);//�����Ժ��VBO���	
//	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);//�����EBO����
//	//glBindVertexArray(0);//��VAO���VAO�л��¼EBO�����ݣ�������Ҫ�����
//
//	glGenVertexArrays(1, &VAO[1]);//����һ��VAO����
//	glGenBuffers(1, &VBO[1]);//����һ��VBO����
//	glBindVertexArray(VAO[1]);//��VAO������Ҫָ��VBO
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);//��ARRAY_BUFFER����ʽ��VBO
//	glBufferData(GL_ARRAY_BUFFER, sizeof(jianbian), jianbian, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);//��0������ 3�� float��ʽ �Ƿ���Ҫ��׼����falseΪ�� ���������������������3��float�� ƫ����
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));//��0������ 3�� float��ʽ �Ƿ���Ҫ��׼����falseΪ�� ���������������������3��float�� ƫ����
//	glEnableVertexAttribArray(1);
//	//glBindBuffer(GL_ARRAY_BUFFER, 0);//�����Ժ��VBO���	
//	//glBindVertexArray(0);//��VAO���VAO�л��¼EBO�����ݣ�������Ҫ�����
//	/**********************************�������********************************/
//	
//	//��Ⱦѭ��
//	while (!glfwWindowShouldClose(window))
//	{//һ��ѭ��Ϊһ֡
//		processInput(window);
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);//״̬���ã�����ĳһ����ɫ
//		glClear(GL_COLOR_BUFFER_BIT);//״̬ʹ�ã�ʹ�øղ����õ���ɫ
//		//glfw:��������������ѯIO�¼�����������/�ͷš�����ƶ��ȣ�
//		glUseProgram(shaderProgram2);//ѡ����ˮ��
//		glBindVertexArray(VAO[1]);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		glBindVertexArray(0);
//
//		glUseProgram(shaderProgram);//ѡ����ˮ��
//		glBindVertexArray(VAO[0]);//��VAO�����߲�����ô����
//		float timeValue = glfwGetTime();//�õ���ǰʱ��
//		float greenValue = (sin(timeValue) / 2.0f) + 0.5f;//����RGB�е�G
//		int vertexColorLocation1 = glGetUniformLocation(shaderProgram, "ourColor1");//�ҵ�shader�е�uniform
//		glUniform4f(vertexColorLocation1, 0.0f, greenValue, 0.0f, 1.0f);
//		glDrawArrays(GL_TRIANGLES, 4, 6);//�ӵ�0����ʼ��3��������ݻ�������
//		
//		float blueValue = (sin(timeValue*2 + pi) / 2.0f) + 0.5f;
//		glUniform4f(vertexColorLocation1, 0.0f, 0.0f, blueValue, 1.0f);
//		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//		float redValue = (sin(timeValue+pi) / 2.0f) + 0.5f;//����RGB�е�R
//		glUniform4f(vertexColorLocation1, redValue, 0.0f, 0.0f, 1.0f);
//		glDrawArrays(GL_TRIANGLES, 10, 6);//�ӵ�0����ʼ��3��������ݻ�������
//		glBindVertexArray(0);
//
//		glfwSwapBuffers(window);//����ͼ��
//		glfwPollEvents();//һЩ�¼�������˵�ص�����
//	}
//	//glfw:����ǰ������GLFW�ȹ���Դ
//	glfwTerminate();
//	glDeleteVertexArrays(1, &VAO[0]);
//	glDeleteBuffers(1, &VBO[0]);
//	glDeleteVertexArrays(1, &VAO[1]);
//	glDeleteBuffers(1, &VBO[1]);
//	glDeleteBuffers(1, &EBO);
//	glDeleteProgram(shaderProgram);
//	glDeleteProgram(shaderProgram2);
//	return 0;
//
//}
//
//void processInput(GLFWwindow *window) {
//	//�˺������ڲ鿴�Ƿ���ESC�������µĻ��͹ر�
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)//release���ǵ�����
//		glfwSetWindowShouldClose(window, true);
//}
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height) {//ʹ���ڿ�����ק����
//	glViewport(0, 0, width, height);
//}

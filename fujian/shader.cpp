#ifndef SHADER_H
#define SHADER_H
#include<glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>

class Shader {
public:
	unsigned int ID;//��ɫ������ID

	//���캯����ȡ������shader
	Shader(const char* vertexPath, const char* fragmentPath);
	void use();//ʹ��/����shader
	//����uniform�Ĺ��ߺ���
	void setBool(const std::string &name, bool value)const;
	void setInt(const std::string& name, int value)const;
	void setFloat(const std::string& name, float value)const;
};
#endif

Shader(const char* vertexPath, const char* fragmentPath) {

}

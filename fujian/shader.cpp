#ifndef SHADER_H
#define SHADER_H
#include<glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>

class Shader {
public:
	unsigned int ID;//着色器程序ID

	//构造函数读取并构建shader
	Shader(const char* vertexPath, const char* fragmentPath);
	void use();//使用/激活shader
	//设置uniform的工具函数
	void setBool(const std::string &name, bool value)const;
	void setInt(const std::string& name, int value)const;
	void setFloat(const std::string& name, float value)const;
};
#endif

Shader(const char* vertexPath, const char* fragmentPath) {

}

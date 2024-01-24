#include "Shader.h"
#include <GL/glew.h>
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(const std::string& vertexPath, const std::string &fragmentPath) :m_ID(0)
{
	// 着色器源代码字符串
	std::string vertexCode;
	std::string fragmentCode;

	std::ifstream vertexFile;
	std::ifstream fragmentFile;
	// 保证ifstream对象可以抛出异常：
	vertexFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fragmentFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		// 打开文件
		vertexFile.open(vertexPath);
		fragmentFile.open(fragmentPath);

		std::stringstream vertexStream, fragmentStream;
		// 读取文件的缓冲内容到数据流中
		vertexStream << vertexFile.rdbuf();
		fragmentStream << fragmentFile.rdbuf();
		// 关闭文件处理器
		vertexFile.close();
		fragmentFile.close();
		// 转换数据流到string
		vertexCode = vertexStream.str();
		fragmentCode = fragmentStream.str();
	}
	catch (const std::exception&)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}

	CreateShader(vertexCode, fragmentCode);
}

Shader::~Shader()
{
	glDeleteProgram(m_ID);
}

void Shader::SetUniformMat4f(const std::string& name, glm::mat4& matrix)
{
	// glm中的矩阵是列主序的，所以不需要转置，因此transpose传GL_FALSE
	glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
}

void Shader::CreateShader(const std::string& vertexSource, const std::string& fragmentSource)
{
	unsigned int vertexShader, fragmentShader;

	// 顶点着色器对象
	vertexShader = CompileShader(GL_VERTEX_SHADER, vertexSource);

	// 片元着色器对象
	fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentSource);

	if (vertexShader > 0 || fragmentShader > 0)
	{
		// 创建着色器程序
		m_ID = glCreateProgram();
		// 关联着色器对象
		if (vertexShader > 0) glAttachShader(m_ID, vertexShader);
		if (fragmentShader > 0) glAttachShader(m_ID, fragmentShader);
		// 链接着色器程序
		glLinkProgram(m_ID);
	}

	// 删除着色器，它们已经链接到我们的程序中了，已经不再需要了
	if (vertexShader > 0) glDeleteShader(vertexShader);
	if (fragmentShader > 0) glDeleteShader(fragmentShader);
}

unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
{
	unsigned int shader;
	// 创建着色器对象
	shader = glCreateShader(type);
	const char* src = source.c_str();
	// 附加着色器源码
	glShaderSource(shader, 1, &src, NULL);
	// 编译着色器对象
	glCompileShader(shader);
	return shader;
}

int Shader::GetUniformLocation(const std::string& name) const 
{
	int location = glGetUniformLocation(m_ID, name.c_str());
	if (location == -1)
		std::cout << "[Warning] uniform " << name << " doesn't exist!" << std::endl;
	return location;
}

void Shader::Bind() const
{
	glUseProgram(m_ID);
}

void Shader::Unbind() const
{
	glUseProgram(0);
}
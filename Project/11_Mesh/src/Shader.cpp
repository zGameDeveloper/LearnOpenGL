#include "Shader.h"
#include <GL/glew.h>
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(const std::string& vertexPath, const std::string &fragmentPath) :m_ID(0)
{
	// ��ɫ��Դ�����ַ���
	std::string vertexCode;
	std::string fragmentCode;

	std::ifstream vertexFile;
	std::ifstream fragmentFile;
	// ��֤ifstream��������׳��쳣��
	vertexFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fragmentFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		// ���ļ�
		vertexFile.open(vertexPath);
		fragmentFile.open(fragmentPath);

		std::stringstream vertexStream, fragmentStream;
		// ��ȡ�ļ��Ļ������ݵ���������
		vertexStream << vertexFile.rdbuf();
		fragmentStream << fragmentFile.rdbuf();
		// �ر��ļ�������
		vertexFile.close();
		fragmentFile.close();
		// ת����������string
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
	// glm�еľ�����������ģ����Բ���Ҫת�ã����transpose��GL_FALSE
	glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
}

void Shader::CreateShader(const std::string& vertexSource, const std::string& fragmentSource)
{
	unsigned int vertexShader, fragmentShader;

	// ������ɫ������
	vertexShader = CompileShader(GL_VERTEX_SHADER, vertexSource);

	// ƬԪ��ɫ������
	fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentSource);

	if (vertexShader > 0 || fragmentShader > 0)
	{
		// ������ɫ������
		m_ID = glCreateProgram();
		// ������ɫ������
		if (vertexShader > 0) glAttachShader(m_ID, vertexShader);
		if (fragmentShader > 0) glAttachShader(m_ID, fragmentShader);
		// ������ɫ������
		glLinkProgram(m_ID);
	}

	// ɾ����ɫ���������Ѿ����ӵ����ǵĳ������ˣ��Ѿ�������Ҫ��
	if (vertexShader > 0) glDeleteShader(vertexShader);
	if (fragmentShader > 0) glDeleteShader(fragmentShader);
}

unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
{
	unsigned int shader;
	// ������ɫ������
	shader = glCreateShader(type);
	const char* src = source.c_str();
	// ������ɫ��Դ��
	glShaderSource(shader, 1, &src, NULL);
	// ������ɫ������
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
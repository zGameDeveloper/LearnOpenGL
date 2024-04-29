#pragma once
#include <string>
#include "vendor/glm/glm.hpp"

class Shader
{
public:
	/// <summary>
	/// ����Դ�����ļ���������ɫ��
	/// </summary>
	/// <param name="vertexPath">������ɫ��Դ�����ļ�·��</param>
	/// <param name="fragmentPath">ƬԪ��ɫ��Դ�����ļ�·��</param>
	Shader(const std::string& vertexPath, const std::string &fragmentPath);

	/// <summary>
	/// ��������
	/// </summary>
	~Shader();

	/// <summary>
	/// ������ɫ������
	/// </summary>
	void Bind() const;

	/// <summary>
	/// ȡ��ʹ����ɫ������
	/// </summary>
	void Unbind() const;

	/// <summary>
	/// ���� uniform 3 ��������ֵ
	/// </summary>
	/// <param name="name">������</param>
	/// <param name="v0">��һ��������</param>
	/// <param name="v1">�ڶ���������</param>
	/// <param name="v2">������������</param>
	void SetUniform3f(const std::string& name, float v0, float v1, float v2);

	/// <summary>
	/// ���� uniform mat4f ����ֵ
	/// </summary>
	/// <param name="name">uniform mat4f ������</param>
	/// <param name="matrix">mat4f ֵ</param>
	void SetUniformMat4f(const std::string& name, glm::mat4& matrix);

	/// <summary>
	/// ���� uniform vec3 ����ֵ
	/// </summary>
	/// <param name="name">������</param>
	/// <param name="vec3">3ά����������</param>
	void SetUniformVec3(const std::string& name, const glm::vec3& value);

private:
	/// <summary>
	/// ��ɫ������ID
	/// </summary>
	unsigned int m_ID;

	/// <summary>
	/// ������ɫ��Դ�����ַ�����������ɫ������
	/// </summary>
	/// <param name="vertexSource">������ɫ��Դ�����ַ���</param>
	/// <param name="fragmentSource">ƬԪ��ɫ��Դ�����ַ���</param>
	void CreateShader(const std::string& vertexSource, const std::string& fragmentSource);

	/// <summary>
	/// ����ɫ��Դ�����ַ���������ָ������ɫ�����ͣ��������ɫ������
	/// </summary>
	/// <param name="type">��ɫ������</param>
	/// <param name="source">��ɫ��Դ�����ַ���</param>
	/// <returns>������ɫ������</returns>
	unsigned int CompileShader(unsigned int type, const std::string& source);

	/// <summary>
	/// ��ȡ uniform ������ location
	/// </summary>
	/// <param name="name">uniform ������</param>
	/// <returns>locationֵ</returns>
	int GetUniformLocation(const std::string& name) const;
};

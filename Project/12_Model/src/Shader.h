#pragma once
#include <string>
#include "vendor/glm/glm.hpp"

class Shader
{
public:
	/// <summary>
	/// 加载源代码文件，构造着色器
	/// </summary>
	/// <param name="vertexPath">顶点着色器源代码文件路径</param>
	/// <param name="fragmentPath">片元着色器源代码文件路径</param>
	Shader(const std::string& vertexPath, const std::string &fragmentPath);

	/// <summary>
	/// 析构函数
	/// </summary>
	~Shader();

	/// <summary>
	/// 启用着色器程序
	/// </summary>
	void Bind() const;

	/// <summary>
	/// 取消使用着色器程序
	/// </summary>
	void Unbind() const;

	/// <summary>
	/// 设置 uniform 3 个浮点数值
	/// </summary>
	/// <param name="name">变量名</param>
	/// <param name="v0">第一个浮点数</param>
	/// <param name="v1">第二个浮点数</param>
	/// <param name="v2">第三个浮点数</param>
	void SetUniform3f(const std::string& name, float v0, float v1, float v2);

	/// <summary>
	/// 设置 uniform mat4f 变量值
	/// </summary>
	/// <param name="name">uniform mat4f 变量名</param>
	/// <param name="matrix">mat4f 值</param>
	void SetUniformMat4f(const std::string& name, glm::mat4& matrix);

	/// <summary>
	/// 设置 uniform vec3 变量值
	/// </summary>
	/// <param name="name">变量名</param>
	/// <param name="vec3">3维浮点数向量</param>
	void SetUniformVec3(const std::string& name, const glm::vec3& value);

private:
	/// <summary>
	/// 着色器程序ID
	/// </summary>
	unsigned int m_ID;

	/// <summary>
	/// 根据着色器源代码字符串，构建着色器对象
	/// </summary>
	/// <param name="vertexSource">顶点着色器源代码字符串</param>
	/// <param name="fragmentSource">片元着色器源代码字符串</param>
	void CreateShader(const std::string& vertexSource, const std::string& fragmentSource);

	/// <summary>
	/// 把着色器源代码字符串，根据指定的着色器类型，编译成着色器对象。
	/// </summary>
	/// <param name="type">着色器类型</param>
	/// <param name="source">着色器源代码字符串</param>
	/// <returns>返回着色器对象</returns>
	unsigned int CompileShader(unsigned int type, const std::string& source);

	/// <summary>
	/// 获取 uniform 变量的 location
	/// </summary>
	/// <param name="name">uniform 变量名</param>
	/// <returns>location值</returns>
	int GetUniformLocation(const std::string& name) const;
};

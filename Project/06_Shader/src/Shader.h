#pragma once
#include <string>

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
};

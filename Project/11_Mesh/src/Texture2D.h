#pragma once
#include <string>

class Texture2D
{
public:
	Texture2D(const std::string &filePath);
	~Texture2D();

	/// <summary>
	/// ������
	/// </summary>
	/// <param name="slot">��ʾ������Ĳ�ۣ������Կ��Ĳ�ͬ����۵�����Ҳ�᲻һ������Windows���ִ��Կ��ϻ���32������Android������ֻ��8����</param>
	void Bind(unsigned int slot = 0) const;
	void Unbind() const;

private:
	unsigned int m_ID;	// �������ID
	int m_Width;
	int m_Height;
};
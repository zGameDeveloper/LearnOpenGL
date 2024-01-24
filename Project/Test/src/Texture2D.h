#pragma once
#include <string>

class Texture2D
{
public:
	Texture2D(const std::string &filePath);
	~Texture2D();

	/// <summary>
	/// 绑定纹理
	/// </summary>
	/// <param name="slot">表示绑定纹理的插槽，根据显卡的不同，插槽的数量也会不一样，在Windows，现代显卡上会有32个；在Android，可能只有8个。</param>
	void Bind(unsigned int slot = 0) const;
	void Unbind() const;

private:
	unsigned int m_ID;	// 纹理对象ID
	int m_Width;
	int m_Height;
};
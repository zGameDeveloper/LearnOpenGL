#include <iostream>
#include "GL/glew.h"
#include "Texture2D.h"
#include "vendor/stb_image/stb_image.h"

Texture2D::Texture2D(const std::string& filePath):m_ID(0), m_Width(0), m_Height(0)
{
	// 垂直翻转纹理
	// opengl 中规则像素从左下角开始，而纹理数据是从图像的顶部到底部，所以需要垂直翻转。
	stbi_set_flip_vertically_on_load(1);

	int comp; // 表示颜色通道的个数
	unsigned char* imgBuffer = stbi_load(filePath.c_str(), &m_Width, &m_Height, &comp, 0);
	if (imgBuffer) 
	{
		std::cout << "comp:" << comp << std::endl;
		unsigned int format = GL_RGB;
		if (comp == 1) format = GL_RED;
		else if (comp == 3) format = GL_RGB;
		else if (comp == 4) format = GL_RGBA;

		glGenTextures(1, &m_ID);
		glBindTexture(GL_TEXTURE_2D, m_ID);

		// 设置纹理参数，不然纹理渲染出来就是黑色的。
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		// 生成一个二维纹理图像
		glTexImage2D(GL_TEXTURE_2D, 0, format, m_Width, m_Height, 0, format, GL_UNSIGNED_BYTE, imgBuffer);
		glGenerateMipmap(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);		
	}
	else 
	{
		std::cout << "Texture failed to load at path: " << filePath << std::endl;
	}

	// 释放纹理缓存
	stbi_image_free(imgBuffer);
}

Texture2D::~Texture2D()
{
	glDeleteTextures(1, &m_ID);
}

void Texture2D::Bind(unsigned int slot) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, m_ID);
}

void Texture2D::Unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
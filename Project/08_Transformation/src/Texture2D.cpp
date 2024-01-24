#include <iostream>
#include "GL/glew.h"
#include "Texture2D.h"
#include "vendor/stb_image/stb_image.h"

Texture2D::Texture2D(const std::string& filePath):m_ID(0), m_Width(0), m_Height(0)
{
	// ��ֱ��ת����
	// opengl �й������ش����½ǿ�ʼ�������������Ǵ�ͼ��Ķ������ײ���������Ҫ��ֱ��ת��
	stbi_set_flip_vertically_on_load(1);

	int comp; // ��ʾ��ɫͨ���ĸ���
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

		// ���������������Ȼ������Ⱦ�������Ǻ�ɫ�ġ�
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		// ����һ����ά����ͼ��
		glTexImage2D(GL_TEXTURE_2D, 0, format, m_Width, m_Height, 0, format, GL_UNSIGNED_BYTE, imgBuffer);
		glGenerateMipmap(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);		
	}
	else 
	{
		std::cout << "Texture failed to load at path: " << filePath << std::endl;
	}

	// �ͷ�������
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
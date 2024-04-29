#ifndef MESH_H
#define MESH_H

#include <vector>
#include "glm/glm.hpp"

/// <summary>
/// ����
/// ˵����C++�ṹ����һ���ܰ������ԣ����ǵ��ڴ沼����������(Sequential)��Ҳ����˵��������ǽ��ṹ����Ϊһ����������ʹ�ã���ô��������˳�����нṹ��ı������⽫��ֱ��ת��Ϊ���������黺��������Ҫ��float��ʵ�������ֽڣ����顣
/// </summary>
struct Vertex
{
	glm::vec3 Position;
};


class Mesh
{
public:
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int>indices);
	void Bind() const;
	void Unbind() const;
private:
	unsigned int m_VBO, m_IBO;
	void setupMesh();
};
#endif
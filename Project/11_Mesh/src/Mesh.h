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
	/// <summary>
	/// ��������
	/// </summary>
	std::vector<Vertex> vertices;

	/// <summary>
	/// ��������
	/// </summary>
	std::vector<unsigned int> indices;

	/// <summary>
	/// ���캯��
	/// </summary>
	/// <param name="vertices">��������</param>
	/// <param name="indices">��������</param>
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int>indices);

	/// <summary>
	/// �󶨣����ƣ�
	/// </summary>
	void Bind() const;

	/// <summary>
	/// �������
	/// </summary>
	void Unbind() const;
private:
	unsigned int m_VBO, m_IBO;
	void setupMesh();
};
#endif
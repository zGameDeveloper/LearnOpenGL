#ifndef MESH_H
#define MESH_H

#include <vector>
#include "glm/glm.hpp"

/// <summary>
/// 顶点
/// 说明：C++结构体有一个很棒的特性，它们的内存布局是连续的(Sequential)。也就是说，如果我们将结构体作为一个数据数组使用，那么它将会以顺序排列结构体的变量，这将会直接转换为我们在数组缓冲中所需要的float（实际上是字节）数组。
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
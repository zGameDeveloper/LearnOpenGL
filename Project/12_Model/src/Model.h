#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <vector>
#include "Mesh.h"
#include "assimp/scene.h"
#include "assimp/Importer.hpp"
#include "assimp/postprocess.h"

class Model
{
public:
	/// <summary>
	/// ���캯��
	/// </summary>
	/// <param name="path">ģ����Դ·��</param>
	Model(const std::string& path);

	/// <summary>
	/// �󶨣���Ⱦ��
	/// </summary>
	void Bind() const;

	/// <summary>
	/// �������
	/// </summary>
	void Unbind() const;
private:
	/// <summary>
	/// Mesh ����
	/// </summary>
	std::vector<Mesh> m_Meshes;

	/// <summary>
	/// ����ڵ�
	/// </summary>
	/// <param name="node">�ڵ�</param>
	/// <param name="scene">����</param>
	void processNode(aiNode* node, const aiScene* scene);

	/// <summary>
	/// ��Assimp�е�Meshת���������Լ���Mesh
	/// </summary>
	/// <param name="mesh">Assimp��Mesh</param>
	/// <param name="scene">����</param>
	/// <returns></returns>
	Mesh  processMesh(aiMesh* mesh, const aiScene* scene);
};

#endif // !MODEL_H


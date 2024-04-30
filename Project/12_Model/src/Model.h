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
	/// 构造函数
	/// </summary>
	/// <param name="path">模型资源路径</param>
	Model(const std::string& path);

	/// <summary>
	/// 绑定（渲染）
	/// </summary>
	void Bind() const;

	/// <summary>
	/// 解绑（清理）
	/// </summary>
	void Unbind() const;
private:
	/// <summary>
	/// Mesh 数组
	/// </summary>
	std::vector<Mesh> m_Meshes;

	/// <summary>
	/// 处理节点
	/// </summary>
	/// <param name="node">节点</param>
	/// <param name="scene">场景</param>
	void processNode(aiNode* node, const aiScene* scene);

	/// <summary>
	/// 将Assimp中的Mesh转换成我们自己的Mesh
	/// </summary>
	/// <param name="mesh">Assimp的Mesh</param>
	/// <param name="scene">场景</param>
	/// <returns></returns>
	Mesh  processMesh(aiMesh* mesh, const aiScene* scene);
};

#endif // !MODEL_H


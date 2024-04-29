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
	Model(const std::string& path);
	void Bind() const;
	void Unbind() const;
private:
	std::vector<Mesh> m_Meshes;
	void processNode(aiNode* node, const aiScene* scene);
	Mesh  processMesh(aiMesh* mesh, const aiScene* scene);
};

#endif // !MODEL_H


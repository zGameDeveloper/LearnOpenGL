#include <iostream>
#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"


void translate()
{
	glm::mat4 trans = glm::translate(glm::mat4(1), glm::vec3(10.0f, 0.0f, 0.0f));
	glm::vec4 pos(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec4 newPos = trans * pos;
	std::cout << "pos x:" << pos.x << ", y:" << pos.y << ", z:" << pos.z << ", w:" << pos.w << std::endl;
	std::cout << "newPos x:" << newPos.x << ", y:" << newPos.y << ", z:" << newPos.z << ", w:" << newPos.w << std::endl;

	glm::vec4 dir(1.0f, 1.0f, 1.0f, 0.0f);
	glm::vec4 newDir = trans * dir;
	std::cout << "dir x:" << dir.x << ", y:" << dir.y << ", z:" << dir.z << ", w:" << dir.w << std::endl;
	std::cout << "newDir x:" << newDir.x << ", y:" << newDir.y << ", z:" << newDir.z << ", w:" << newDir.w << std::endl;
}

void scale()
{
	glm::mat4 scale = glm::scale(glm::vec3(2.0f, 2.0f, 2.0f));
	glm::vec4 pos(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec4 newPos = scale * pos;
	std::cout << "pos x:" << pos.x << ", y:" << pos.y << ", z:" << pos.z << ", w:" << pos.w << std::endl;
	std::cout << "newPos x:" << newPos.x << ", y:" << newPos.y << ", z:" << newPos.z << ", w:" << newPos.w << std::endl;

	glm::vec4 dir(1.0f, 1.0f, 1.0f, 0.0f);
	glm::vec4 newDir = scale * dir;
	std::cout << "dir x:" << dir.x << ", y:" << dir.y << ", z:" << dir.z << ", w:" << dir.w << std::endl;
	std::cout << "newDir x:" << newDir.x << ", y:" << newDir.y << ", z:" << newDir.z << ", w:" << newDir.w << std::endl;
}

void rotate()
{
	glm::mat4 rotate = glm::rotate(glm::radians(90.0f), glm::vec3(1, 0, 0));
	glm::vec4 pos(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec4 newPos = rotate * pos;
	std::cout << "pos x:" << pos.x << ", y:" << pos.y << ", z:" << pos.z << ", w:" << pos.w << std::endl;
	std::cout << "newPos x:" << newPos.x << ", y:" << newPos.y << ", z:" << newPos.z << ", w:" << newPos.w << std::endl;

	glm::vec4 dir(1.0f, 1.0f, 1.0f, 0.0f);
	glm::vec4 newDir = rotate * dir;
	std::cout << "dir x:" << dir.x << ", y:" << dir.y << ", z:" << dir.z << ", w:" << dir.w << std::endl;
	std::cout << "newDir x:" << newDir.x << ", y:" << newDir.y << ", z:" << newDir.z << ", w:" << newDir.w << std::endl;
}

void model_matrix() 
{
	// ÈÆxÖáÐý×ª-55¶È
	glm::mat4 model = glm::rotate(glm::radians(-55.0f), glm::vec3(1, 0, 0));
}

bool loadModel(std::string path)
{
	Assimp::Importer import;
	const aiScene * scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		std::cout << "ERROR::ASSIMP::" << import.GetErrorString() << std::endl;
		return false;
	}

	std::cout << "LoadFinish! The count of vertice :" << (*(scene->mMeshes))->mNumVertices << std::endl;

	return true;
}

int main(void)
{	
	glm::mat4 rotate = glm::rotate(glm::radians(90.0f), glm::vec3(1, 0, 0));
	glm::vec4 pos(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec4 newPos = rotate * pos;
	std::cout << "pos x:" << pos.x << ", y:" << pos.y << ", z:" << pos.z << ", w:" << pos.w << std::endl;
	std::cout << "newPos x:" << newPos.x << ", y:" << newPos.y << ", z:" << newPos.z << ", w:" << newPos.w << std::endl;

	glm::vec4 dir(1.0f, 1.0f, 1.0f, 0.0f);
	glm::vec4 newDir = rotate * dir;
	std::cout << "dir x:" << dir.x << ", y:" << dir.y << ", z:" << dir.z << ", w:" << dir.w << std::endl;
	std::cout << "newDir x:" << newDir.x << ", y:" << newDir.y << ", z:" << newDir.z << ", w:" << newDir.w << std::endl;

	loadModel("res/models/fels.3ds");

	return 0;
}
#include <iostream>
#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"


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
	return 0;
}
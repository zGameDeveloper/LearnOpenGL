#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "src/Model.h"
#include "src/Shader.h"
#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include <vector>

const unsigned int screen_width = 640;
const unsigned int screen_height = 480;

Shader* shader;
Model* model;

void init() {   

    // ��ɫ��
    shader = new Shader("res/shaders/Basic.vert", "res/shaders/Basic.frag");
    shader->Bind();
    model = new Model("res/models/fels.3ds");
    // view
    glm::mat4 viewMatrix = glm::lookAt(
        glm::vec3(0, 0, 10),     // �����������λ��
        glm::vec3(0, 0, 0),     // ������۲��
        glm::vec3(0, 1, 0)      // ��������Ϸ�������
    );
    shader->SetUniformMat4f("view", viewMatrix);
    // projection: ͸��ͶӰ fov=45, ��߱�, ������=0.1, Զ����=100
    glm::mat4 projectionMatrix = glm::perspective(glm::radians(45.0f), screen_width * 1.0f / screen_height, 0.1f, 100.0f);
    shader->SetUniformMat4f("projection", projectionMatrix);
    shader->SetUniformVec3("color", glm::vec3(1, 0, 0));
}

void display() {
    // model
    glm::mat4 modelMatrix = glm::rotate((float)glfwGetTime(), glm::vec3(1,0,0));
    shader->SetUniformMat4f("model", modelMatrix);

    // ����
    model->Bind();
}

void clear() {
    model->Unbind();
}

// main
int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(screen_width, screen_height, "Model", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // glew init
    if (glewInit() != GLEW_OK) {
        std::cout << "glew init error!" << std::endl;
    }

    // print opengl version
    std::cout << "OpenGL version :" << glGetString(GL_VERSION) << std::endl;

    /* init */
    init();


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* display */
        display();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();

    /* clear */
    clear();
    return 0;
}
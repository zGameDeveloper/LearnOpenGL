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
Model* m_Model;

void init() {   

    // 着色器
    shader = new Shader("res/shaders/Basic.vert", "res/shaders/Basic.frag");
    shader->Bind();
    m_Model = new Model("res/models/fels.3ds");
    // view
    glm::mat4 view = glm::lookAt(
        glm::vec3(0, 0, 10),     // 摄像机的世界位置
        glm::vec3(0, 0, 0),     // 摄像机观察点
        glm::vec3(0, 1, 0)      // 摄像机向上方向向量
    );
    shader->SetUniformMat4f("view", view);
    // projection: 透视投影 fov=45, 宽高比, 近截面=0.1, 远截面=100
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), screen_width * 1.0f / screen_height, 0.1f, 100.0f);
    shader->SetUniformMat4f("projection", projection);
    shader->SetUniformVec3("color", glm::vec3(1, 0, 0));
}

void display() {
    // model
    glm::mat4 transform = glm::rotate((float)glfwGetTime(), glm::vec3(1,0,0));
    shader->SetUniformMat4f("model", transform);

    // 绘制
    m_Model->Bind();
}

void clear() {
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
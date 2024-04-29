#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "src/Mesh.h"
#include <vector>

const unsigned int screen_width = 640;
const unsigned int screen_height = 480;

Mesh* mesh;

void init() {
    // 顶点数据
    std::vector<Vertex> vertices = {
        {glm::vec3(-0.5f, -0.5f, 0.0f)},
        {glm::vec3(-0.5f,  0.5f, 0.0f)},
        {glm::vec3( 0.5f,  0.5f, 0.0f)},
        {glm::vec3( 0.5f, -0.5f, 0.0f)}
    };

    // 绘制顶点的顺序
    std::vector<unsigned int> indices = {
        0, 1, 2,    // 第一个三角形的顶点数组下标
        2, 0, 3     // 第二个三角形的顶点数组下标
    };

     mesh = new Mesh(vertices, indices);    
}

void display() {
    // 绘制
    mesh->Bind();
}

void clear() {
    mesh->Unbind();
}

// main
int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(screen_width, screen_height, "Mesh", NULL, NULL);
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
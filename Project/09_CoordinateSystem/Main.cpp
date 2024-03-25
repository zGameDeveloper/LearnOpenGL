#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "src/Shader.h"
#include "src/Texture2D.h"
#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"

const unsigned int screen_width = 640;
const unsigned int screen_height = 480;
unsigned int VBO;
unsigned int IBO;

Texture2D* tex;
Shader* shader;

void init() {
    // ��������
    float vertices[] = {
        // --- position ---     --- color ---   - texture -
          -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, // ���½�
          -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, // ���Ͻ�
           0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, // ���Ͻ�
           0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f  // ���½�
    };

    // ���ƶ����˳��
    unsigned int indices[] = {
        0, 1, 2,    // ��һ�������εĶ��������±�
        2, 0, 3     // �ڶ��������εĶ��������±�
    };

    // ����һ����������������洢��VBO
    glGenBuffers(1, &VBO);
    // ���������󶨵�GL_ARRAY_BUFFER
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // �Ѷ������ݸ��Ƶ���ǰ�󶨵Ļ������
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // ����һ����������������洢��IBO
    glGenBuffers(1, &IBO);
    // ���������󶨵�GL_ELEMENT_ARRAY_BUFFER
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    // �Ѷ����������ݸ��Ƶ���ǰ�󶨵Ļ������
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // --- λ������ ---
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), 0);
    glEnableVertexAttribArray(0);

    // --- ��ɫ���� ---
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (void*)(3 * sizeof(GL_FLOAT)));
    glEnableVertexAttribArray(1);

    // --- �������� ---
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (void*)(6 * sizeof(GL_FLOAT)));
    glEnableVertexAttribArray(2);

    // ����    
    tex = new Texture2D("res/textures/OpenGL.png");
    // ������󶨵���Ӧ������Ԫ�ϲ�����
    tex->Bind();
    

    // ��ɫ��
    shader = new Shader("res/shaders/Basic.vert", "res/shaders/Basic.frag");   
    shader->Bind();

    // model:��x����ת-60��
    glm::mat4 model = glm::rotate(glm::radians(-60.0f), glm::vec3(1, 0, 0));
    // view
    glm::mat4 view = glm::lookAt(
        glm::vec3(0, 0, 6),     // �����������λ��
        glm::vec3(0, 0, 0),     // ������۲��
        glm::vec3(0, 1, 0)      // ��������Ϸ�������
    );
    // projection: ͸��ͶӰ fov=45, ��߱�, ������=0.1, Զ����=100
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), screen_width * 1.0f / screen_height, 0.1f, 100.0f);
    glm::mat4 mvp = projection * view * model;
    shader->SetUniformMat4f("mvp", mvp);
}

void display() {
    // ����
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void clear() {
    // ɾ���������
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &IBO);
}

// main
int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(screen_width,screen_height, "CoordinateSystem", NULL, NULL);
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
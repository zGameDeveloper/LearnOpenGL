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
    // 顶点数据
    float vertices[] = {
        // --- position ---     --- color ---   - texture -
          -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, // 左下角
          -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, // 左上角
           0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, // 右上角
           0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f  // 右下角
    };

    // 绘制顶点的顺序
    unsigned int indices[] = {
        0, 1, 2,    // 第一个三角形的顶点数组下标
        2, 0, 3     // 第二个三角形的顶点数组下标
    };

    // 创建一个缓存对象名，并存储到VBO
    glGenBuffers(1, &VBO);
    // 将缓存对象绑定到GL_ARRAY_BUFFER
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // 把顶点数据复制到当前绑定的缓存对象
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // 创建一个缓存对象名，并存储到IBO
    glGenBuffers(1, &IBO);
    // 将缓存对象绑定到GL_ELEMENT_ARRAY_BUFFER
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    // 把顶点索引数据复制到当前绑定的缓存对象
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // --- 位置属性 ---
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), 0);
    glEnableVertexAttribArray(0);

    // --- 颜色属性 ---
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (void*)(3 * sizeof(GL_FLOAT)));
    glEnableVertexAttribArray(1);

    // --- 纹理属性 ---
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (void*)(6 * sizeof(GL_FLOAT)));
    glEnableVertexAttribArray(2);

    // 纹理    
    tex = new Texture2D("res/textures/OpenGL.png");
    // 将纹理绑定到相应的纹理单元上并激活
    tex->Bind();
    

    // 着色器
    shader = new Shader("res/shaders/Basic.vert", "res/shaders/Basic.frag");   
    shader->Bind();

    // model:绕x轴旋转-60度
    glm::mat4 model = glm::rotate(glm::radians(-60.0f), glm::vec3(1, 0, 0));
    // view
    glm::mat4 view = glm::lookAt(
        glm::vec3(0, 0, 6),     // 摄像机的世界位置
        glm::vec3(0, 0, 0),     // 摄像机观察点
        glm::vec3(0, 1, 0)      // 摄像机向上方向向量
    );
    // projection: 透视投影 fov=45, 宽高比, 近截面=0.1, 远截面=100
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), screen_width * 1.0f / screen_height, 0.1f, 100.0f);
    glm::mat4 mvp = projection * view * model;
    shader->SetUniformMat4f("mvp", mvp);
}

void display() {
    // 绘制
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void clear() {
    // 删除缓存对象
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
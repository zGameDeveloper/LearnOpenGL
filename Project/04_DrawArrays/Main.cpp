#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

unsigned int VBO;

void init() {
    // 设置顶点数据
    float vertices[] = {
       -0.5f, -0.5f, 0.0f, // 左下角
       -0.5f,  0.5f, 0.0f, // 左上角
        0.5f,  0.5f, 0.0f, // 右上角

        0.5f,  0.5f, 0.0f, // 右上角
       -0.5f, -0.5f, 0.0f, // 左下角
        0.5f, -0.5f, 0.0f  // 右下角
    };

    // 创建一个缓存对象名
    glGenBuffers(1, &VBO);
    // 绑定缓存对象，并激活
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // 把顶点数据复制到当前绑定的缓存对象
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // 链接顶点属性
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), 0);
    // 启用顶点属性
    glEnableVertexAttribArray(0);
}

void display() {
    // 绘制
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void clear() {
    // 删除缓存对象
    glDeleteBuffers(1, &VBO);
}

// main
int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "DrawArrays", NULL, NULL);
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
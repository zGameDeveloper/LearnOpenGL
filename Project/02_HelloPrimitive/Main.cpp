#include <GLFW/glfw3.h>

struct POINT
{
    float x, y;
};

void DrawPoint(float x, float y, float size = 1.0f) {
    // 设置质点大小
    glPointSize(size);
    glBegin(GL_POINTS);
    glVertex3f(x, y, 0);
    glEnd();
}

void DrawLine(float x1, float y1, float x2, float y2, float width = 1.0f) {
    // 设置线段宽度
    glLineWidth(width);
    glBegin(GL_LINES);
    glVertex3f(x1, y1, 0);
    glVertex3f(x2, y2, 0);
    glEnd();
}

void DrawPolygon(const POINT* points, int num) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < num; i++)
    {
        glVertex3f(points[i].x, points[i].y, 0);
    }
    glEnd();
}


int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "HelloPrimitive", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Draw point with 4.0 size */
        DrawPoint(-0.8f, 0.5f, 4);

        /* Draw line with 4.0 width */
        DrawLine(-0.3f, 0.4f, 0.2f, 0.7, 4.0f);

        /* Draw triangle */
        POINT triangle[] = { {0.5, 0.3}, {0.5, 0.7}, {0.9, 0.7} };
        DrawPolygon(triangle, 3);

        /* Draw quad */
        POINT quad[] = { {-0.9f, -0.7f}, {-0.9f, -0.3f}, {-0.5f, -0.3f}, {-0.5f, -0.7f} };
        DrawPolygon(quad, 4);

        /*Draw polygon */
        POINT pts[] = { {0.3f, -0.5f},{0.4f, -0.6732f},{0.6f, -0.6732f}, {0.7, -0.5},{0.6f, -0.3268f}, {0.4f, -0.3268f} };
        DrawPolygon(pts, 6);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
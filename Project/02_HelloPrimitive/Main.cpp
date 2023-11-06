#include <GLFW/glfw3.h>

void DrawPoint(float x0, float y0) {
    glPointSize(4);
    glBegin(GL_POINTS);
    glVertex3f(x0, y0, 0);
    glEnd();
}

void DrawLine(float x0, float y0, float edge) {
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex3f(x0, y0, 0);
    glVertex3f(x0 + edge, y0, 0);
    glEnd();
}

void DrawTriangle(float x0, float y0, float edge) {
    glBegin(GL_TRIANGLES);
    glVertex3f(x0, y0, 0);
    glVertex3f(x0, y0 + edge, 0);
    glVertex3f(x0 + edge, y0 + edge, 0);
    glEnd();
}

void DrawQuad(float x0, float y0, float edge) {
    glBegin(GL_QUADS);
    glVertex3f(x0, y0, 0);
    glVertex3f(x0, y0 + edge, 0);
    glVertex3f(x0 + edge, y0 + edge, 0);
    glVertex3f(x0 + edge, y0, 0);
    glEnd();
}

void DrawPolygon(float x0, float y0, float edge) {
    glBegin(GL_POLYGON);
    glVertex3f(x0, y0, 0);
    glVertex3f(x0 - 0.5f * edge, y0 + 0.5f * edge, 0);
    glVertex3f(x0 - 0.5f * edge, y0 + 1.2f * edge, 0);
    glVertex3f(x0, y0 + 1.7f * edge, 0);
    glVertex3f(x0 + edge, y0 + 1.7f * edge, 0);
    glVertex3f(x0 + 1.5f * edge, y0 + 1.2f * edge, 0);
    glVertex3f(x0 + 1.5f * edge, y0 + 0.5f * edge, 0);
    glVertex3f(x0 + edge, y0, 0);
    glEnd();
}


int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "DrawPrimitive", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }


    if (!glIsEnabled(GL_POLYGON_SMOOTH)) {
        glEnable(GL_POLYGON_SMOOTH);
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glViewport(0, 0, 640, 480);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Draw point with 4.0 size */
        DrawPoint(-0.8f, 0.5f);
      
        /* Draw line with 4.0 width */
        DrawLine(-0.3f, 0.5f, 0.4f);

        /* Draw triangle */
        DrawTriangle(0.5f, 0.3f, 0.4f);

        /* Draw quad */
        DrawQuad(-0.9f, -0.8f, 0.4f);

        /*Draw polygon */
        DrawPolygon(0.0f, -0.8f, 0.4f);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
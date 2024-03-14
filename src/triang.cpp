// #include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
void drawPoint()
{
    /* Draw a point */
    glClearColor(0.0, 0.0, 0.0, 0.0);
    // glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(10.0f);
    glBegin(GL_POINTS);

    glEnd();
}
void drawLint()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(2); // 设置线段宽度
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.8, 1); // 定点坐标范围
    glVertex2f(0, -1);
    glEnd();
}
void drawTriangle()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0); // Red
    glVertex3f(0.0, 1.0, 0.0);
    glColor3f(0.0, 1.0, 0.0); // Green
    glVertex3f(-1.0, -1.0, 0.0);
    glColor3f(0.0, 0.0, 1.0); // Blue
    glVertex3f(1.0, -1.0, 0.0);
    glEnd();
}
void framebuffer_size_callback(GLFWwindow *window, int w, int h)
{
    glViewport(0, 0, w, h);
}
int main(void)
{

    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(500, 500, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    // GLFWimage images[1];
    // images[0].height = 2;
    // images[0].width = 2;
    // images[0].pixels = (unsigned char *)malloc(sizeof(unsigned char) * images[0].height * images[0].width * 4);
    // printf("%llu %c\n", images[0].pixels[0]);
    // images[0].pixels[0] = 255;
    // images[0].pixels[1] = 0;
    // images[0].pixels[2] = 0;
    // images[0].pixels[3] = 255;
    // images[0].pixels[4] = 0;
    // images[0].pixels[5] = 255;
    // images[0].pixels[6] = 0;
    // images[0].pixels[7] = 255;
    // images[0].pixels[8] = 0;
    // images[0].pixels[9] = 0;
    // images[0].pixels[10] = 255;
    // images[0].pixels[11] = 255;
    // images[0].pixels[12] = 255;
    // images[0].pixels[13] = 0;
    // images[0].pixels[14] = 255;
    // images[0].pixels[15] = 255;
    // printf("%llu %c\n", images[0].pixels[0]);
    // printf("%llu", sizeof(unsigned char));

    // glfwSetWindowIcon(window, 1, images);
    int width = 512, height = 512, nrChannels = 3;
    GLFWimage images[1];
    unsigned char *data = stbi_load("..\\art_assets\\images\\icon.png", &width, &height, &nrChannels, 4);
    if (data)
    {
        // glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        // glGenerateMipmap(GL_TEXTURE_2D);
        images[0].height = width;
        images[0].width = height;
        images[0].pixels = data;
        glfwSetWindowIcon(window, 1, images);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* compute */

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();
        drawPoint();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
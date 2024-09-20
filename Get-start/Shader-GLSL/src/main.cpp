#include <iostream>
#include <math.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "vao.h"
#include "vbo.h"
#include "ebo.h"
#include "shader.h"

int width = 1024,height = 1024;

GLfloat vertices[] = 
{
    0.0f, 0.5f, 0.0f,               1.0f, 0.0f, 0.0f, 
    -0.25f * sqrt(3), -0.25f, 0.0f, 0.0f, 1.0f, 0.0f, 
    0.25f * sqrt(3), -0.25f, 0.0f,  0.0f, 0.0f, 1.0f,
};


int main()
{

    glfwInit();
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(width, height ,"Shader-Test", NULL, NULL);

    if (window == nullptr)
    {
        std::cout << "Failed to create a window object!" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
        return -1;
    }

    glfwMakeContextCurrent(window);
    gladLoadGL();

    // NOTICE: The position of glfwMakeContextCurrent and gladLoadGL
    // CANNOT be replaced by each other,or program does not work properly.

    glViewport(0,0,width,height);

    // VAO & VBO

    VAO vao;
    vao.Bind();
    VBO vbo(vertices, sizeof(vertices));
    vao.LinkVBO(vbo, 0);
    vao.LinkVBO(vbo, 1);

    vao.UnBind();
    vbo.UnBind();

    // Shader

    Shader shaderProgram("G:\\OpenGL\\Get-start\\Shader-GLSL\\resources\\vertexes\\vertex.glsl",
        "G:\\OpenGL\\Get-start\\Shader-GLSL\\resources\\fragments\\fragment.glsl");

    // Program
    
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClearColor(0.2f,0.3f,0.3f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        vao.Bind();
        shaderProgram.Activate();

        // Animation 
        GLfloat time = glfwGetTime();
        GLfloat val = (sin(time / 1.2) / 4) + 0.5;
        GLint vertexColorLocation = glGetUniformLocation(shaderProgram.Program, "myColor"); 
        glUniform1f(vertexColorLocation, val);        

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    vao.Delete();
    vbo.Delete();
    shaderProgram.Delete();
    glfwTerminate();
    return 0;

}
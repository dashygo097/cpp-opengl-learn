#include <iostream>
#include <math.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "vao.h"
#include "vbo.h"
#include "ebo.h"
#include "shader.h"

auto width = 1024,height = 1024;

GLfloat vertices[] = 
{
    -0.25f + sqrt(2)/16, 0.25f + sqrt(2)/16, 0.0f,
    0.25f + sqrt(2)/16, 0.25f + sqrt(2)/16, 0.0f,
    -0.25f - sqrt(2)/16, 0.25f- sqrt(2)/16, 0.0f,
    0.25f- sqrt(2)/16,  0.25f- sqrt(2)/16, 0.0f,
    -0.25f- sqrt(2)/16, -0.25f- sqrt(2)/16, 0.0f,
    0.25f- sqrt(2)/16, -0.25f- sqrt(2)/16, 0.0f,
    0.25f + sqrt(2)/16, -0.25f + sqrt(2)/16, 0.0f,
    -0.25f + sqrt(2)/16, -0.25f + sqrt(2)/16, 0.0f,

};


GLuint indices[] = 
{
    0,1,2,
    1,2,3,
    2,3,4,
    3,4,5,
    3,5,6,
    1,3,6,
};

int main()
{

    // Transform
    for(int i = 0;i < 24;i++)
    {
        vertices[i] *= 1.5;  
    }
    glfwInit();
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(width, height ,"Cube", NULL, NULL);

    if (window == nullptr)
    {
        std::cout << "Failed to create a window object!" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    gladLoadGL();
    // NOTICE: The position of glfwMakeContextCurrent and gladLoadGL
    // CANNOT be replaced by each other,or program does not work properly.

    glViewport(0,0,width,height);

    // VAO & VBO

    VAO VAO_Surface;
    VAO_Surface.Bind();
    VBO VBO_Surface(vertices,sizeof(vertices));
    EBO EBO_Surface(indices, sizeof(indices));
    VAO_Surface.LinkVBO(VBO_Surface, 0); 

    VAO_Surface.UnBind();
	VBO_Surface.UnBind();
    EBO_Surface.Unbind();

    // Shader

    Shader surface1("G:\\OpenGL\\Get-start\\Cube-organised\\resources\\vertexes\\vertex.glsl",
        "G:\\OpenGL\\Get-start\\Cube-organised\\resources\\fragments\\surface1.glsl");
    Shader surface2("G:\\OpenGL\\Get-start\\Cube-organised\\resources\\vertexes\\vertex.glsl",
        "G:\\OpenGL\\Get-start\\Cube-organised\\resources\\fragments\\surface2.glsl");
    Shader surface3("G:\\OpenGL\\Get-start\\Cube-organised\\resources\\vertexes\\vertex.glsl",
        "G:\\OpenGL\\Get-start\\Cube-organised\\resources\\fragments\\surface3.glsl");

    // Program
    
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClearColor(0.2f,0.3f,0.3f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        
        VAO_Surface.Bind();
        surface1.Activate();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);
        surface2.Activate();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(sizeof(int)*6));
        surface3.Activate();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(sizeof(int)*12));


        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    VAO_Surface.Delete();
	VBO_Surface.Delete();
    EBO_Surface.Delete();
	surface1.Delete();
    surface2.Delete();
    surface3.Delete();
    glfwTerminate();
    return 0;

}
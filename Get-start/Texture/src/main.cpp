#include <iostream>
#include <math.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

#include "vao.h"
#include "vbo.h"
#include "ebo.h"
#include "shader.h"


int width = 1024,height = 1024, numColth;

GLfloat vertices[] = 
{
     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    
};

GLuint indices[] = 
{
    0,1,3,
    1,2,3
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
    EBO ebo(indices, sizeof(indices));
    vao.Bind();
    ebo.Bind();
    VBO vbo(vertices, sizeof(vertices));
    vbo.Bind();
    vao.LinkVBO(vbo,0);
    vao.LinkVBO(vbo,1);
    vao.LinkVBO(vbo,2);

    vao.UnBind();
    ebo.Unbind();

    // Load Texture

    vao.Bind();
    stbi_set_flip_vertically_on_load_thread(true);
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    unsigned char* image = stbi_load("./resources/textures/me.jpg", 
        &width, &height, &numColth, 0);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(image);
    glBindTexture(GL_TEXTURE_2D, 0);
    vao.UnBind();
    

    // Shader

    Shader shaderProgram("./resources/vertexes/vertex.glsl",
        "./resources/fragments/fragment.glsl");

    // Program
    
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClearColor(0.2f,0.3f,0.3f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shaderProgram.Activate();

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);
        glUniform1i(glGetUniformLocation(shaderProgram.Program, "Texture"), 0);
        vao.Bind();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        // Animation 


        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glDeleteTextures(1, &texture);
    vao.Delete();
    vbo.Delete();
    shaderProgram.Delete();
    glfwTerminate();
    return 0;

}
#include <iostream>
#include <math.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "vao.h"
#include "vbo.h"
#include "ebo.h"
#include "shader.h"
#include "texture.h" 



int width = 2048,height = 2048, numColth;

GLfloat vertices[] = 
{
    -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
     0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
     0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
     0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
     0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f
};

GLuint indices[36];


int main()
{

    // Indices 
    for(int i = 0 ; i < 36;i++)
    {
        indices[i] = i;
    }


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
    glEnable(GL_DEPTH_TEST);

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

    // Texture

    vao.Bind();
    // stbi_set_flip_vertically_on_load_thread(true);
    Texture texture;
    texture.Load_Image("./resources/textures/me.jpg",
        width, height, numColth);
    texture.Bind();
    vao.UnBind();
    texture.UnBind();    

    // 3D & Transform

    GLfloat I_4[] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
    glm::mat4 trans = glm::make_mat4x4(I_4); 
    glm::mat4 view = glm::make_mat4x4(I_4);
    glm::mat4 model = glm::make_mat4x4(I_4);
    glm::mat4 projection = glm::make_mat4x4(I_4);
    GLfloat rotate_angle = M_PI * 0.5;
    trans = glm::scale(trans, glm::vec3(0.33f, 0.33f, 0.33f));
    model = glm::rotate(model,(float)(-55.0f/180.0f * M_PI),
         glm::vec3(1.0f, 0.5f, 0.7f));
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -2.0f));
    projection = glm::perspective((float)(45.0f/180.0f * M_PI), (float)width / (float)height, 0.1f, 100.0f);
    // Shader

    Shader shaderProgram("./resources/vertexes/vertex.glsl",
        "./resources/fragments/fragment.glsl");

    // Program
    GLfloat time_last = glfwGetTime();
    
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glClearColor(0.2f,0.3f,0.3f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shaderProgram.Activate();

        texture.Activate();
        texture.Bind();
        glUniform1i(glGetUniformLocation(shaderProgram.Program, "Texture"), 0);
        vao.Bind();

        // 3D Space
        GLint modelLoc = glGetUniformLocation(shaderProgram.Program, "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        GLint projectionLoc = glGetUniformLocation(shaderProgram.Program, "projection");
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
        GLint viewLoc = glGetUniformLocation(shaderProgram.Program, "view");
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));


        // Animation
        GLfloat time = glfwGetTime();
        GLfloat delta = time - time_last;
        time_last = glfwGetTime();
        GLuint transformLoc = glGetUniformLocation(shaderProgram.Program, "transform");
        rotate_angle = M_PI* delta ;
        trans = glm::rotate(trans, (float)rotate_angle, glm::vec3(0.0f, 0.0f ,1.0f));
        glUniformMatrix4fv(transformLoc,1, GL_FALSE, glm::value_ptr(trans));   

        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        vao.UnBind();

        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    texture.Delete();
    vao.Delete();
    vbo.Delete();
    shaderProgram.Delete();
    glfwTerminate();
    return 0;

}
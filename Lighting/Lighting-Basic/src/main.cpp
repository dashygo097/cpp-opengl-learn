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
#include "camera.h"


int width = 1600,height = 1600, numColth;

// Camera & Keymap & Curser
Camera camera(width, height);
bool keys[1024];

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void do_movements();
void do_floats();

GLfloat yaw    = -90.0f ;	
GLfloat pitch  =  0.0f;
GLfloat lastX  =  width  / 2.0;
GLfloat lastY  =  height / 2.0;
GLfloat fov =  45.0f ;


GLfloat vertices[] = 
{
    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
     0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

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

glm::vec3 objects[] = 
{
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(3.0f, -1.0f, 2.0f),
    glm::vec3(2.0f, 2.0f, 2.0f),
};


int main()
{
    // indices
    for (int i = 0 ; i < 36; i++)
    {
        indices[i] = i;
    }


    glfwInit();
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(width, height ,"Lighting-Test", NULL, NULL);

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
    glfwSetKeyCallback(window, key_callback);  
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // NOTICE: The position of glfwMakeContextCurrent and gladLoadGL
    // CANNOT be replaced by each other,or program does not work properly.

    glViewport(0,0,width,height);

    // lightVAO & VBO

    EBO ebo(indices, sizeof(indices));
    VAO lightVAO;
    lightVAO.Bind();
    ebo.Bind();
    VBO vbo(vertices, sizeof(vertices));
    lightVAO.LinkVBO(vbo,0);
    lightVAO.LinkVBO(vbo,1);
    lightVAO.LinkVBO(vbo,2);

    lightVAO.UnBind();
    ebo.Unbind();
    vbo.UnBind();

    // Texture & Color

    glm::vec3 lightColor = glm::vec3(1.0f, 1.0f,1.0f);
    glm::vec3 cubeColor[] = 
    {
        glm::vec3(1.0f, 0.5f, 0.0f),
        glm::vec3(0.0f, 0.0f, 1.0f),
    };
    glm::vec3 lineColor = glm::vec3(0.0f, 0.0f, 0.0f);


    // 3D & Transform

    GLfloat I_4[] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
    glm::mat4 projection = glm::make_mat4x4(I_4);
    glm::mat4 trans = glm::make_mat4x4(I_4);
    projection = glm::perspective((float)(45.0f/180.0f * M_PI), (float)width / (float)height, 0.1f, 100.0f);

    // Shader

    Shader shaderProgram("./resources/vertexes/vertex.glsl",
        "./resources/fragments/fragment.glsl");

    // Program
    GLfloat time_last = glfwGetTime();
    
    while (!glfwWindowShouldClose(window))
    {
        GLfloat time = glfwGetTime();
        GLfloat delta = time - time_last;
        time_last = glfwGetTime();

        glfwPollEvents();
        do_movements();
        do_floats();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glClearColor(0.0f,0.0f,0.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        lightVAO.Bind();
        shaderProgram.Activate();

        // 3D Space

        GLint modelLoc = glGetUniformLocation(shaderProgram.Program, "model");
        GLint projectionLoc = glGetUniformLocation(shaderProgram.Program, "projection");
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

        // Animation

        GLint transLoc = glGetUniformLocation(shaderProgram.Program, "transform");
        glUniformMatrix4fv(transLoc, 1, GL_FALSE, glm::value_ptr(trans));
        GLint viewLoc = glGetUniformLocation(shaderProgram.Program, "view");
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera.view));

        // Lighting object

        GLint lightColorLoc = glGetUniformLocation(shaderProgram.Program, "lightColor");
        GLint objectColorLoc = glGetUniformLocation(shaderProgram.Program, "objectColor");
        glUniform3fv(lightColorLoc,1 ,&lightColor[0]);
        
        glm::mat4 model = glm::make_mat4x4(I_4);
        model = glm::translate(model, objects[2]);
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniform3fv(objectColorLoc, 1, &glm::vec3(1.0f, 1.0f, 1.0f)[0]);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


        for (int i = 0 ;i < 2; i++)
        {
            // Draw the object
            glm::mat4 model = glm::make_mat4x4(I_4);
            model = glm::translate(model, objects[i]);
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            glUniform3fv(objectColorLoc, 1, &cubeColor[i][0]);
            glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

            // Draw the border 
            glUniform3fv(objectColorLoc,1 ,&lineColor[0]);
            glDrawElements(GL_LINE_STRIP,36 ,GL_UNSIGNED_INT, 0);
            
        }

        lightVAO.UnBind();
        glfwSwapBuffers(window);

    }

    glfwDestroyWindow(window);
    lightVAO.Delete();
    vbo.Delete();
    ebo.Delete();
    shaderProgram.Delete();
    glfwTerminate();
    return 0;

}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key <= 1023 && key >= 0)
    {
        if (action == GLFW_PRESS)
        {
            keys[key] = true;
        }
        else if (action == GLFW_RELEASE) 
        {
            keys[key] = false;
        }
    }

}

void do_movements()
{
    if(keys[GLFW_KEY_W])
    {
        glm::vec3 clip = camera.front.y * camera.up;
        glm::vec3 direc = camera.front - clip; 
        camera.Speed +=  0.00005f * glm::normalize(direc);
        camera.Pos += camera.Speed * camera.weight;
        camera.Move();
    }
    if(keys[GLFW_KEY_S])
    {
        glm::vec3 clip = camera.front.y * camera.up;
        glm::vec3 direc = camera.front - clip; 
        camera.Speed -=  0.00005f * glm::normalize(direc);
        camera.Pos += camera.Speed * camera.weight ;
        camera.Move();
    }
    if(keys[GLFW_KEY_A])
    {
        glm::vec3 direc = 0.0f - glm::cross(camera.front, camera.up);
        glm::vec3 clip = direc.y * camera.up;
        camera.Speed +=  0.00005f * glm::normalize(direc);
        camera.Pos +=  camera.Speed * camera.weight * 0.2f ;
        camera.Move();
    }
    if(keys[GLFW_KEY_D])
    {
        
        glm::vec3 direc = glm::cross(camera.front, camera.up);
        glm::vec3 clip = direc.y * camera.up;
        camera.Speed +=  0.00005f * glm::normalize(direc);
        camera.Pos +=  camera.Speed * camera.weight * 0.2f;
        camera.Move();
    }
    if(keys[GLFW_KEY_SPACE])
    {
        camera.Speed += 0.00005f * camera.up;
        camera.Pos += camera.weight * 0.03f * camera.Speed;
        camera.Move();
    }   
    if (keys[GLFW_KEY_LEFT_SHIFT])
    {
        camera.Speed -=  0.00005f * camera.up;
        camera.Pos += camera.weight * 0.03f * camera.Speed;
        camera.Move();
    } 

}

void do_floats()
{
    glm::vec3 clip = camera.front.y * camera.up;
    glm::vec3 direc = camera.front - clip; 
    camera.Speed *= 0.995f;

    if (glm::length(camera.Speed) < 0.000001f)
    {
        camera.Speed *= 0.0f;
    } 
    camera.Pos += camera.Speed  ;
    camera.Move();  
}



bool firstMouse = true;
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    GLfloat xoffset = xpos - lastX;
    GLfloat yoffset = lastY - ypos; 
    lastX = xpos;
    lastY = ypos;

    GLfloat sensitivity = 0.02;	
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw   += xoffset;
    pitch += yoffset;


    if (pitch > 89.0f )
    {
        pitch = 89.0f;
    }
    if (pitch < -89.0f)
    {
        pitch = -89.0f;
    }

    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    camera.front = glm::normalize(front);
    camera.Move();
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.weight += yoffset* 0.01f ;
    if (camera.weight < 0.0f)
    {
        camera.weight = 0.0f;
    }
}

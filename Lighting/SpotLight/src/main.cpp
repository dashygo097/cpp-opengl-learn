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
#include "extension.h"

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



std::vector<Vertex> vertices = 
{
    Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 0.0f)),
    Vertex(glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(1.0f, 1.0f)),
    Vertex(glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(1.0f, 1.0f)),
    Vertex(glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(0.0f, 1.0f)),
    Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f)),

    Vertex(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 0.0f)),
    Vertex(glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(1.0f,1.0f)),
    Vertex(glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(1.0f,1.0f)),
    Vertex(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(0.0f, 1.0f)),
    Vertex(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 0.0f)),

    Vertex(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(1.0f, 0.0f)),
    Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 1.0f)),
    Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 1.0f)),
    Vertex(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 1.0f)),
    Vertex(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(0.0f, 0.0f)),

    Vertex(glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(1.0f, 0.0f)),
    Vertex(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 1.0f)),
    Vertex(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 1.0f)),
    Vertex(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 1.0f)),
    Vertex(glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(0.0f, 0.0f)),

    Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 0.0f)),
    Vertex(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 1.0f)),
    Vertex(glm::vec3(0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 1.0f)),
    Vertex(glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 1.0f)),
    Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f)),

    Vertex(glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(0.0f, 0.0f)),
    Vertex(glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(1.0f, 0.0f)),
    Vertex(glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(1.0f, 1.0f)),
    Vertex(glm::vec3(0.5f, 0.5f, 0.5f), glm::vec2(1.0f, 1.0f)),
    Vertex(glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(0.0f, 1.0f)),
    Vertex(glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(0.0f, 0.0f))

};

std::vector<GLuint> indices;

glm::vec3 objects[] = 
{
    glm::vec3(-1.0f, 0.0f, 1.0f),
    glm::vec3(3.0f, -1.0f, 2.0f),
    glm::vec3(-4.0f, 4.0f, 4.0f),
    glm::vec3(2.0f, 2.0f, 2.0f),
};


int main()
{
    // indices
    for (int i = 0 ; i < 36; i++)
    {
        indices.push_back(i);
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

    get_normal_raw(vertices);

    EBO ebo(indices);
    VAO lightVAO;
    lightVAO.Bind();
    ebo.Bind();
    VBO vbo(vertices);
    lightVAO.LinkVBO(vbo,0);
    lightVAO.LinkVBO(vbo,1);
    lightVAO.LinkVBO(vbo,2);
    lightVAO.LinkVBO(vbo,3);

    lightVAO.UnBind();
    ebo.Unbind();
    vbo.UnBind();

    // Texture & Color

    glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3 cubeColor[] = 
    {
        glm::vec3(1.0f, 1.0f, 1.0f),
        glm::vec3(1.0f, 1.0f, 1.0f),
        glm::vec3(1.0f, 1.0f, 1.0f)
    };
    glm::vec3 lineColor = glm::vec3(1.0f, 1.0f, 1.0f);
    
    lightVAO.Bind();
    Texture texture_1;
    texture_1.Load_Image("./resources/textures/container2.png",width,height,numColth);
    texture_1.UnBind();
    Texture texture_2;
    texture_2.Load_Image("./resources/textures/container2_specular.png",width,height,numColth);
    lightVAO.UnBind();

    // 3D & Transform

    GLfloat I_4[] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
    glm::mat4 projection = glm::make_mat4x4(I_4);
    glm::mat4 trans = glm::make_mat4x4(I_4);
    projection = glm::perspective((float)(45.0f/180.0f * M_PI), (float)width / (float)height, 0.1f, 100.0f);

    // Shaders

    Shader objectShader("./resources/vertices/object.vert",
        "./resources/fragments/object.frag");

    Shader lightShader("./resources/vertices/object.vert",
        "./resources/fragments/light.frag");

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

        glClearColor(0.02f,0.01f,0.01f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        lightVAO.Bind();

        // OBJECTS
        objectShader.Activate();

        // 3D Space

        GLint modelLoc = glGetUniformLocation(objectShader.Program, "model");
        GLint projectionLoc = glGetUniformLocation(objectShader.Program, "projection");
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

        // Animation

        GLint transLoc = glGetUniformLocation(objectShader.Program, "transform");
        glUniformMatrix4fv(transLoc, 1, GL_FALSE, glm::value_ptr(trans));
        GLint viewLoc = glGetUniformLocation(objectShader.Program, "view");
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera.view));

        // Draw

        GLint objectColorLoc = glGetUniformLocation(objectShader.Program, "objectColor");
        GLint viewPosLoc = glGetUniformLocation(objectShader.Program, "viewPos");

        GLint shineLoc = glGetUniformLocation(objectShader.Program, "material.shininess");

        GLint lightStrengthLoc = glGetUniformLocation(objectShader.Program, "light.strength");
        GLint lightCutoffLoc = glGetUniformLocation(objectShader.Program, "light.cutoff");
        GLint lightOuterCutoffLoc = glGetUniformLocation(objectShader.Program, "light.outercutoff");
        GLint lightPosLoc = glGetUniformLocation(objectShader.Program, "light.position");
        GLint lightDirLoc = glGetUniformLocation(objectShader.Program, "light.direction");
        GLint lightColorLoc = glGetUniformLocation(objectShader.Program, "light.color");
        GLint lightAmbientLoc = glGetUniformLocation(objectShader.Program, "light.ambient");
        GLint lightDiffuseLoc = glGetUniformLocation(objectShader.Program, "light.diffuse");
        GLint lightSpecularLoc = glGetUniformLocation(objectShader.Program, "light.specular");

        glUniform1f(shineLoc, 16.0f);

        glUniform1f(lightStrengthLoc, 50.0f); 
        glUniform1f(lightCutoffLoc, glm::cos(glm::radians(15.0f)));
        glUniform1f(lightOuterCutoffLoc, glm::cos(glm::radians(20.0f))); 
        glUniform3f(lightPosLoc, camera.Pos.x, camera.Pos.y, camera.Pos.z);
        glUniform3f(lightDirLoc, camera.front.x, camera.front.y, camera.front.z);
        glUniform3fv(lightColorLoc, 1, &lightColor[0]);
        glUniform3f(lightAmbientLoc, 0.1f, 0.1f, 0.1f);
        glUniform3f(lightDiffuseLoc, 0.4f, 0.4f, 0.4f);
        glUniform3f(lightSpecularLoc, 3.0f, 3.0f, 3.0f);

        texture_1.Activate();
        texture_1.Bind();
        glUniform1i(glGetUniformLocation(objectShader.Program, "material.diffuse"), 0);
        texture_2.Activate();
        texture_2.Bind();
        glUniform1i(glGetUniformLocation(objectShader.Program, "material.specular"), 1);

        glm::mat4 model = glm::make_mat4x4(I_4);
        for (int i = 0 ;i < 3; i++)
        {
            // Draw the object
            model = glm::translate(model, objects[i]);
            model = glm::rotate(model, float(-55.0f / 180.0f * M_PI), glm::vec3(1.0f, 0.5f, 0.7f));
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

            // Draw the border 
            glUniform3fv(objectColorLoc,1 ,&lineColor[0]);
            glDrawElements(GL_LINE_STRIP,36 ,GL_UNSIGNED_INT, 0);
            
        } 


        // // LIGHTING OBJECTS
        // lightShader.Activate();

        // // 3D Space

        // modelLoc = glGetUniformLocation(lightShader.Program, "model");
        // projectionLoc = glGetUniformLocation(lightShader.Program, "projection");
        // glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

        // // Animation

        // transLoc = glGetUniformLocation(lightShader.Program, "transform");
        // glUniformMatrix4fv(transLoc, 1, GL_FALSE, glm::value_ptr(trans));
        // viewLoc = glGetUniformLocation(lightShader.Program, "view");
        // glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera.view));

        // // Draw 

        // lightColorLoc = glGetUniformLocation(lightShader.Program, "lightColor");
        // glUniform3fv(lightColorLoc,1 ,&lightColor[0]);

        // model = glm::make_mat4x4(I_4); 
        // model = glm::translate(model, objects[3]);
        // model = glm::scale(model,glm::vec3(0.2f, 0.2f, 0.2f));
        // glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        // glUniform3fv(objectColorLoc, 1, &lightColor[0]);
        // glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

        lightVAO.UnBind();
        glfwSwapBuffers(window);

    }

    glfwDestroyWindow(window);
    lightVAO.Delete();
    vbo.Delete();
    ebo.Delete();
    objectShader.Delete();
    lightShader.Delete();
    texture_1.Delete();
    texture_2.Delete();
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

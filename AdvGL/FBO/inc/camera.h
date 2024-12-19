#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Camera
{
public:

    Camera(int width, int height);

    GLfloat yaw    = -90.0f ;	
    GLfloat pitch  =  0.0f;
    GLfloat fov =  45.0f ;
    GLfloat lastX;
    GLfloat lastY;
    glm::vec3 Pos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::mat4 view = glm::lookAt(Pos, front, up);

    glm::vec3 Speed = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 floats = glm::vec3(0.0f, 0.0f, 0.0f);
    GLfloat weight = 0.002f;

    bool keys[1024];

    bool firstMouse = true;

    void Move();
    void StareAt(glm::vec3 target);
    void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
    void mouseCallback(GLFWwindow* window, double xpos, double ypos);

};


#endif 

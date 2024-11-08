#include "camera.h"

Camera::Camera(int width, int height)
{
    lastX  =  width  / 2.0;
    lastY  =  height / 2.0;
}

void Camera::Move()
{
    view = glm::lookAt(Pos, Pos + front, up);
}

void Camera::StareAt(glm::vec3 target)
{
    view = glm::lookAt(Pos, target, up);
}


void Camera::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
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

void Camera::mouseCallback(GLFWwindow* window, double xpos, double ypos)
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
    front = glm::normalize(front);
    Move();
}

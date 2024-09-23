#include "camera.h"

Camera::Camera(int width, int height)
{
    GLfloat lastX  =  width  / 2.0;
    GLfloat lastY  =  height / 2.0;
}

void Camera::Move()
{
    view = glm::lookAt(Pos, Pos + front, up);
}

void Camera::StareAt(glm::vec3 target)
{
    view = glm::lookAt(Pos, target, up);
}

#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include <glad/glad.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Vertex
{
public:

    Vertex(glm::vec3 pos);
    Vertex(glm::vec3 pos, glm::vec3 color);
    Vertex(glm::vec3 pos, glm::vec3 color, glm::vec2 texture);
    Vertex(glm::vec3 pos, glm::vec3 nor, glm::vec3 color, glm::vec2 texture);
    glm::vec3 pos;
    glm::vec3 nor;
    glm::vec3 color;
    glm::vec2 texture;
};


class VBO
{
public:
    GLuint ID;
    VBO(std::vector<Vertex>& vertices);

    void Bind();
    void UnBind();
    void Delete();
};


#endif 
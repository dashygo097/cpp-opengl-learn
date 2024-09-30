#include "vbo.h"
#include <iostream>

Vertex::Vertex(glm::vec3 pos_reg)
{
    pos = pos_reg;
    nor = glm::vec3(0.0f, 0.0f, 0.0f);
    color = glm::vec3(1.0f, 1.0f, 1.0f);
    texture = glm::vec2(0.0f, 0.0f);
}

Vertex::Vertex(glm::vec3 pos_reg, glm::vec2 texture_reg)
{
    pos = pos_reg;
    nor = glm::vec3(0.0f, 0.0f, 0.0f);
    color = glm::vec3(1.0f, 1.0f, 1.0f);
    texture = texture_reg;
}


Vertex::Vertex(glm::vec3 pos_reg, glm::vec3 nor_reg)
{
    pos = pos_reg;
    nor = nor_reg;
    color = glm::vec3(1.0f, 1.0f ,1.0f);
    texture = glm::vec2(0.0f, 0.0f);
}

Vertex::Vertex(glm::vec3 pos_reg, glm::vec3 color_reg,glm::vec2 texture_reg)
{
    pos = pos_reg;
    nor = glm::vec3(0.0f, 0.0f, 0.0f);
    color = color_reg;
    texture = texture_reg;
}

Vertex::Vertex(glm::vec3 pos_reg, glm::vec3 nor_reg,
    glm::vec3 color_reg, glm::vec2 texture_reg)
{
    pos = pos_reg;
    nor = nor_reg;
    color = color_reg;
    texture = texture_reg;
}


VBO::VBO(std::vector<Vertex>& vertices)
{
    glGenBuffers(1 , &ID);
    glBindBuffer(GL_ARRAY_BUFFER, ID);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * 
        sizeof(Vertex), vertices.data() , GL_STATIC_DRAW);
}

void VBO::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::UnBind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0); 
}

void VBO::Delete()
{
    glDeleteBuffers(1 ,&ID);
}
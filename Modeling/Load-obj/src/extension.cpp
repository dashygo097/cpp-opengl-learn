#include "extension.h"

void get_normal_raw(std::vector<Vertex>& vertices)
{
    // Get the normal vector of vertices without indices
    int num = vertices.size();
    glm::vec3 v1;
    glm::vec3 v2;
    glm::vec3 pos1;
    glm::vec3 pos2;
    glm::vec3 pos3;
    glm::vec3 normal;
    glm::vec3 G = get_G(vertices);
    for (int i = 0 ; i < num / 3; i++)
    {
        pos1 = vertices[3*i].pos;
        pos2 = vertices[3*i + 1].pos;
        pos3 = vertices[3*i + 2].pos;
        v1 = pos3 - pos1;
        v2 = pos3 - pos2;
        normal = glm::normalize(glm::cross(v1, v2));
        if (glm::dot(normal, pos1 - G) < 0.0f)
        {
            normal = 0.0f - normal;
        }
        vertices[3*i].nor = normal;
        vertices[3*i + 1].nor = normal;
        vertices[3*i + 2].nor = normal;
    }
}

void get_normal(std::vector<Vertex>& vertices, std::vector<GLuint>& indices)
{
    glm::vec3 v1;
    glm::vec3 v2;
    glm::vec3 pos1;
    glm::vec3 pos2;
    glm::vec3 pos3;
    glm::vec3 normal;
    glm::vec3 G = get_G(vertices);
    for (int i = 0 ; i < indices.size() / 3; i ++)
    {
        pos1 = vertices[indices[3*i]].pos;
        pos2 = vertices[indices[3*i + 1]].pos;
        pos3 = vertices[indices[3*i + 2]].pos;
        v1 = pos3 - pos1;
        v2 = pos3 - pos2;
        normal = glm::normalize(glm::cross(v1, v2));
        if (glm::dot(normal, pos1 - G) < 0.0f)
        {
            normal = 0.0f - normal;
        }
        vertices[indices[3*i]].nor += normal;
        vertices[indices[3*i + 1]].nor += normal;
        vertices[indices[3*i + 2]].nor += normal;
    }
    for (auto vertex : vertices)
    {
        vertex.nor = glm::normalize(vertex.nor);
    }

}

glm::vec3 get_G(std::vector<Vertex>& vertices)
{
    glm::vec3 G(0.0f);
    int index = 0;
    for (auto vertex : vertices)
    {
        for (int i = 0 ; i < index; i++)
        {
            if (vertex.pos == vertices[i].pos)continue;
        } 
        G += vertex.pos / float(vertices.size());
        index ++;
    }
    return G;
}

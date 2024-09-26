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
    for (int i = 0 ; i < num / 3; i++)
    {
        pos1 = vertices[3*i].pos;
        pos2 = vertices[3*i + 1].pos;
        pos3 = vertices[3*i + 2].pos;
        v1 = pos3 - pos1;
        v2 = pos3 - pos2;
        normal = glm::normalize(glm::cross(v1, v2));
        if (glm::dot(normal, pos1) < 0.0f)
        {
            normal = 0.0f - normal;
        }
        vertices[3*i].nor = normal;
        vertices[3*i + 1].nor = normal;
        vertices[3*i + 2].nor = normal;
    }
}
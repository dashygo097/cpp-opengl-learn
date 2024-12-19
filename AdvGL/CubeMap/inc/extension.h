#ifndef EXTENSION_CLASS_H
#define EXTENSION_CLASS_H

#include <glad/glad.h>

#include "mesh.h"

void get_normal_raw(std::vector<Vertex>& vertices);
void get_normal(std::vector<Vertex>& vertices, std::vector<GLuint>& indices);
glm::vec3 get_G(std::vector<Vertex>& vertices);

#endif

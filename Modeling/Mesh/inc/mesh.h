#ifndef MESH_CLASS_H
#define MESH_CLASS_H

#include "vbo.h"
#include "vao.h"
#include "ebo.h"
#include "texture.h"
#include "shader.h"

class Mesh
{
public:

    Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures);

    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    std::vector<Texture> textures;

    VAO vao;
    VBO vbo;
    EBO ebo;

    void setupMesh();
    void Draw(Shader& shader);
    void Delete();

};

#endif
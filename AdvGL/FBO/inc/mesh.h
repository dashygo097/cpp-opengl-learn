#ifndef MESH_CLASS_H
#define MESH_CLASS_H

#include "vbo.h"
#include "vao.h"
#include "ebo.h"
#include "texture.h"
#include "shader.h"
#include "extension.h"

class Mesh
{
public:

    Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures,
        bool is_normal_obtained = false);
    Mesh(std::string obj_path, std::string texture_path= "",
        bool is_normal_obtained = false);

    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    std::vector<Texture> textures;

    VAO vao;
    VBO vbo;
    EBO ebo;

    void setupMesh(bool normal_obtained = false);
    void Draw(Shader& shader);
    void Delete();

};

class LightMesh : Mesh
{

};


#endif
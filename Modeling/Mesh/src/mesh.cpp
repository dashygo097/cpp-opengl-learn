#include "mesh.h"

Mesh::Mesh(std::vector<Vertex> ver, std::vector<GLuint> ind, std::vector<Texture> tex)
{
    this->vertices = ver;
    this->indices = ind;
    this->textures = tex; 

    setupMesh();
}

void Mesh::setupMesh()
{
    this->vao.Bind();
    this->ebo.Bind();

    this->ebo.Setup(this->indices);
    this->vbo.Setup(this->vertices);

    vao.LinkVBO(vbo,0);
    vao.LinkVBO(vbo,1);
    vao.LinkVBO(vbo,2);
    vao.LinkVBO(vbo,3);

    vao.UnBind();
    ebo.Unbind();
    vbo.UnBind();

}

void Mesh::Draw(Shader& shader)
{
    unsigned int numDiffuse = 0;
    unsigned int numSpecular = 0;
    std::string uniform; 
    for(unsigned int i = 0; i < textures.size(); i++)
    {
        textures[i].Activate();
        std::string number;
        std::string name = textures[i].type;
        if(name == "diffuse")
        {
            number = std::to_string(++numDiffuse);
        }
        else if(name == "specular")
        {
            number = std::to_string(++numSpecular);
        }
        uniform = "material_" + number + "." + name;
        shader.setInt(uniform.c_str(), i);
        glBindTexture(GL_TEXTURE_2D, textures[i].ID);
    }

    vao.Bind();
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    vao.UnBind();
}


void Mesh::Delete()
{
    vao.Delete();
    ebo.Delete();
    vbo.Delete();
    for (int i = 0 ; i < textures.size(); i++)
    {
        textures.pop_back();
    }
}


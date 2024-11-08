#include "mesh.h"

Mesh::Mesh(std::vector<Vertex> ver, std::vector<GLuint> ind, std::vector<Texture> tex,
    bool is_normal_obtained)
{
    this->vertices = ver;
    this->indices = ind;
    this->textures = tex; 

    setupMesh(is_normal_obtained);
}

Mesh::Mesh(std::string obj_path, std::string texture_path,
     bool is_normal_obtained)
{
    std::ifstream file(obj_path, std::ios::in);
    if (file.is_open() == false)
    {
        std::cerr << "Failed to load obj: " << obj_path << std::endl;
    }

    std::string line;
    glm::vec3 ver;
    GLuint indice;
    glm::vec2 texCoord;
    while (getline(file, line))
    {
        std::istringstream iss(line);
        std::string prefix;
        iss >> prefix;

        if (prefix == "v")
        {
            iss >> ver.x ;
            iss >> ver.y ;
            iss >> ver.z ;  
            ver = ver / 50.0f;
            Vertex vertex(ver);
            vertices.push_back(vertex);
        }
        else if (prefix == "f")
        {
            for (int i = 0 ; i < 3; i++)
            {
                iss >> indice;
                indices.push_back(indice - 1);
            }
        }
    }

    setupMesh(is_normal_obtained);
}


void Mesh::setupMesh(bool is_normal_obtained)
{
    
    if (!is_normal_obtained)
    {
        get_normal(vertices,indices);
    }

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
        shader.set1d(uniform.c_str(), i);
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

SkyboxMesh::SkyboxMesh(std::vector<Vertex> ver, std::vector<GLuint> ind, std::vector<std::string> faces, 
    bool is_normal_obtained)
{
    this->vertices = ver;
    this->indices = ind;
    this->cubemap = CubemapTexture(faces);

    setupMesh(is_normal_obtained);
}

void SkyboxMesh::setupMesh(bool is_normal_obtained)
{
    if (!is_normal_obtained)
    {
        get_normal(vertices, indices);
    }

    this->vao.Bind();
    this->ebo.Bind();

    this->ebo.Setup(this->indices);
    this->vbo.Setup(this->vertices);

    vao.LinkVBO(vbo, 0);
    vao.LinkVBO(vbo, 1);
    vao.LinkVBO(vbo, 2);
    vao.LinkVBO(vbo, 3);

    vao.UnBind();
    ebo.Unbind();
    vbo.UnBind();
}

void SkyboxMesh::Draw(Shader& shader)
{
    cubemap.Activate();
    shader.set1d("skybox", 0);  
    glBindTexture(GL_TEXTURE_CUBE_MAP, cubemap.ID);

    vao.Bind();
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    vao.UnBind();
}

void SkyboxMesh::Delete()
{
    vao.Delete();
    ebo.Delete();
    vbo.Delete();
    cubemap.Delete();
}


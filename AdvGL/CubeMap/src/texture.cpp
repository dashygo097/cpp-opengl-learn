#include "texture.h"

Texture::Texture()
{
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);
}

Texture::Texture(std::string type)
{
    this->type = type;   
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);

}

void Texture::Load_Image(const GLchar* texturePath,
    int width, int height, int numColth)
{
    unsigned char* image = stbi_load(texturePath,
        &width, &height, &numColth, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(image);
}

void Texture::Load_Unit(Shader& shader, std::string uniform, GLuint unit)
{
    GLuint texUnit = glGetUniformLocation(shader.Program, uniform.c_str());

    shader.Activate();
    glUniform1i(texUnit, unit);
}

void Texture::Bind()
{
    glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::Activate()
{
    glActiveTexture(GL_TEXTURE0 + ID - 1);

}

void Texture::UnBind()
{
    glBindTexture(GL_TEXTURE_2D,0);
}

void Texture::Delete()
{
    glDeleteTextures(1, &ID);
}

CubemapTexture::CubemapTexture()
{

}

CubemapTexture::CubemapTexture(std::vector<std::string> faces)
{
    glGenTextures(1, &ID);
    Bind();

    int width, height, numColth;
    unsigned char* image;
    for (GLuint i = 0; i < faces.size(); i ++)
    {
        image = stbi_load(faces[i].c_str(), &width, &height, &numColth, 0);
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
        stbi_image_free(image);
    }

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
}

void CubemapTexture::Bind()
{
    glBindTexture(GL_TEXTURE_CUBE_MAP, ID);
}

void CubemapTexture::Activate()
{
    glActiveTexture(GL_TEXTURE0 + ID - 1);
}

void CubemapTexture::UnBind()
{
    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}

void CubemapTexture::Delete()
{
    glDeleteTextures(1, &ID);
}
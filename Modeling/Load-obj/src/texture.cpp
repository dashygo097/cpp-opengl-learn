#include "texture.h"

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
    glBindTexture(GL_TEXTURE_2D,ID);
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

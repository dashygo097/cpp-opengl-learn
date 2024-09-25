#include "texture.h"

Texture::Texture()
{
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);

}

void Texture::Load_Image(const GLchar* texturePath,
    int width, int height, int numColth)
{
    unsigned char* image = stbi_load(texturePath,
        &width, &height, &numColth, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(image);
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

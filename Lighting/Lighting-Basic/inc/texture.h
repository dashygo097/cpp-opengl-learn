#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include <glad/glad.h>
#include <iostream>
#include <stb/stb_image.h>

class Texture
{
public:
    GLuint ID;

    Texture();

    void Load_Image(const GLchar* texturePath,
        int width, int height, int NumCloth);
    void Bind();
    void Activate();
    void UnBind();
    void Delete();
};


#endif 
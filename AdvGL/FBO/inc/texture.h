#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include <glad/glad.h>
#include <stb/stb_image.h>

#include "shader.h"

class Texture
{
public:
    GLuint ID;
    std::string type;
    GLuint unit;

    Texture();
    Texture(std::string type);

    void Load_Image(const GLchar* texturePath,
        int width, int height, int NumCloth);
    void Load_Unit(Shader& shader, std::string uniform, GLuint unit);
    void Bind();
    void Activate();
    void UnBind();
    void Delete();
};


#endif 

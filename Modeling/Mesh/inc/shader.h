#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include <iostream>
#include <glad/glad.h>
#include <fstream>
#include <sstream>
#include <string>

std::string read_file(const GLchar* filePath);

class Shader
{
public:
    GLuint Program;
    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
    void Activate();

    void setInt(const std::string& name, int value);



    void Delete();
};


#endif 

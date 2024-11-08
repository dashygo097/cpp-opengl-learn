#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "vbo.h"

std::string read_file(const GLchar* filePath);

class Shader
{
public:
    GLuint Program;
    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
    void Activate();

    void set1d(const std::string& name, int value);
    void set1f(const std::string& name, float value);
    void set3f(const std::string& name, float value1, float value2, float value3);
    void set3fv(const std::string& name, glm::vec3 value);

    void Delete();
};

class LightProperty
{
public:
    LightProperty(std::string type, glm::vec3 value);
    std::string type;
    glm::vec3 value;
};

class LightLoader
{
public:
    
    GLuint ID;
    std::vector<LightProperty> light;
    std::string type;

    LightLoader(std::string type, std::vector<LightProperty>& light);

    void handler(Shader shader);   

};


#endif 
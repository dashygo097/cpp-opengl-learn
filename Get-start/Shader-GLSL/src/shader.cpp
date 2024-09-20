#include "shader.h"

std::string read_file(const GLchar* filePath)
{
    std::string Code;
    std::ifstream File;
    File.exceptions(std::ifstream::badbit);
    try 
    {
        File.open(filePath);
        std::stringstream Stream;
        Stream << File.rdbuf();
        File.close();
        Code = Stream.str();
    }
    catch(std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    return Code;
}


Shader::Shader(const GLchar* vertexPath, const GLchar* fragmentPath)
{
    // Read Files
    std::string vCodeReader = read_file(vertexPath);
    std::string fCodeReader = read_file(fragmentPath);

    const GLchar* vShaderCode = vCodeReader.c_str();
    const GLchar* fShaderCode = fCodeReader.c_str();

    // Compile Shader 
    GLuint vertex,fragment;
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode,NULL);
    glCompileShader(vertex);
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode,NULL);
    glCompileShader(fragment);

    // Program
    this->Program = glCreateProgram();

    glAttachShader(this->Program, vertex);
    glAttachShader(this->Program, fragment);
    glLinkProgram(this->Program);

    glDeleteShader(vertex);
    glDeleteShader(fragment);

}

void Shader::Activate()
{
    glUseProgram(this->Program);
}

void Shader::Delete()
{
    glDeleteShader(this->Program);
}
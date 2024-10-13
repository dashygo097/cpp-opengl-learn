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


void Shader::set1d(const std::string& name, int value)
{
    GLuint uniform = glGetUniformLocation(Program, name.c_str());
    glUniform1i(uniform, value);
}


void Shader::set1f(const std::string& name, float value)
{
    GLuint uniform = glGetUniformLocation(Program, name.c_str());
    glUniform1f(uniform, value);
}


void Shader::set3f(const std::string& name, float value1, float value2, float value3)
{
    GLuint uniform = glGetUniformLocation(Program, name.c_str());
    glUniform3f(uniform, value1, value2, value3);
}

void Shader::set3fv(const std::string& name, glm::vec3 value)
{
    GLuint uniform = glGetUniformLocation(Program, name.c_str());
    glUniform3fv(uniform, 1, &value[0]);
}


void Shader::Delete()
{
    glDeleteShader(this->Program);
}

LightProperty::LightProperty(std::string type, glm::vec3 value)
{
    this->type = type;
    this->value = value;
}


LightLoader::LightLoader(std::string type, std::vector<LightProperty>& light)
{
    this->type = type;
    this->light = light;
}

void LightLoader::handler(Shader shader)
{
    if (type == "pointlight" || type == "PointLight" || type == "Pointlight")
    {
        unsigned int numStrength = 0;
        unsigned int numPosition = 0;
        unsigned int numColor = 0;
        unsigned int numAmbient = 0;
        unsigned int numDiffuse = 0;
        unsigned int numSpecular = 0;
        std::string uniform; 
        for(unsigned int i = 0; i < light.size(); i++)
        {
            std::string number;
            std::string name = light[i].type;
            if(name == "strength")
            {
                number = std::to_string(++numStrength);
            }
            else if(name == "position")
            {
                number = std::to_string(++numPosition);
            }            
            else if(name == "color")
            {
                number = std::to_string(++numColor);
            }            
            else if(name == "ambient")
            {
                number = std::to_string(++numAmbient);
            }            
            else if(name == "diffuse")
            {
                number = std::to_string(++numDiffuse);
            }            
            else if(name == "specular")
            {
                number = std::to_string(++numSpecular);
            }
            uniform = "light_" + number + "." + name;

            if (light[i].type == "strength")
            {
                shader.set1f(uniform.c_str(), light[i].value[0]);
            }
            else 
            {
                shader.set3fv(uniform.c_str(), light[i].value);
            }
        } 
    }

    else if (type == "Spotlight" || type == "spotLight" || type == "SpotLight")
    {
        unsigned int numStrength = 0;
        unsigned int numCutoff = 0;
        unsigned int numOutercutoff = 0;
        unsigned int numDirection = 0;
        unsigned int numPosition = 0;
        unsigned int numColor = 0;
        unsigned int numAmbient = 0;
        unsigned int numDiffuse = 0;
        unsigned int numSpecular = 0;
        std::string uniform; 
        for(unsigned int i = 0; i < light.size(); i++)
        {
            std::string number;
            std::string name = light[i].type;
            if(name == "strength")
            {
                number = std::to_string(++numStrength);
            }
            else if(name == "position")
            {
                number = std::to_string(++numPosition);
            }
            else if(name == "cutoff")
            {
                number = std::to_string(++numCutoff);
            }
            else if(name == "outercutoff")
            {
                number = std::to_string(++numOutercutoff);
            }
            else if(name == "direction")
            {
                number = std::to_string(++numDirection);
            }            
            else if(name == "color")
            {
                number = std::to_string(++numColor);
            }            
            else if(name == "ambient")
            {
                number = std::to_string(++numAmbient);
            }            
            else if(name == "diffuse")
            {
                number = std::to_string(++numDiffuse);
            }            
            else if(name == "specular")
            {
                number = std::to_string(++numSpecular);
            }
            uniform = "light_" + number + "." + name;

            if (light[i].type == "strength")
            {
                shader.set1f(uniform.c_str(), light[i].value[0]);
            }
            else if (light[i].type == "cutoff" || light[i].type == "outercutoff")
            {
                shader.set1f(uniform.c_str(), glm::cos(glm::radians(light[i].value[0])));
            }
            else 
            {
                shader.set3fv(uniform.c_str(), light[i].value);
            }
        } 
    }
}

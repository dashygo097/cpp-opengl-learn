#include "shader.h"

std::string file = read_file("G:\\OpenGL\\Get-start\\Cube-organised\\resources\\fragment.glsl");
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

int main()
{
    std::cout << file.c_str() << std::endl;
    std::cout << fragmentShaderSource;
    return 0;
}
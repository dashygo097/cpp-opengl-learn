#version 330 core
in vec3 Color;

out vec4 fragmentColor; 

void main()
{
    fragmentColor = vec4(Color, 1.0f);
}
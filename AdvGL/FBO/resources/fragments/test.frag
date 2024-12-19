#version 330 core
out vec4 Color;

uniform vec3 myColor;

void main()
{
    Color = vec4(myColor, 1.0f); 
}

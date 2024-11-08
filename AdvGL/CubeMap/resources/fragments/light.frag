#version 330 core
out vec4 Color;

uniform vec3 lightColor;

void main()
{
    Color = vec4(lightColor, 1.0f); 
}
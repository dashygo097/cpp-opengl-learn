#version 330 core

out vec4 Color;

uniform vec3 lightColor;
uniform vec3 objectColor;

void main()
{
    Color = vec4(lightColor * objectColor, 1.0f);
}
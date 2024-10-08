#version 330 core
layout (location = 0) in vec3 position; 
layout (location = 1) in vec3 vertexColor;
uniform float myColor;

out vec3 Color; 

void main()
{
    gl_Position = vec4(position, 1.0); 
    Color = vertexColor * myColor; 
}
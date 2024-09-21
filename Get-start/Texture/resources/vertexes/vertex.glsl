#version 330 core
layout (location = 0) in vec3 position; 
layout (location = 1) in vec3 vertexColor;
layout (location = 2) in vec2 textureCoord;

out vec3 Color; 
out vec2 Coord;

void main()
{
    gl_Position = vec4(position, 1.0); 
    Color = vertexColor;
    Coord = textureCoord;
}
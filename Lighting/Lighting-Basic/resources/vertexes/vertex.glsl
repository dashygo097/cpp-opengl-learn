#version 330 core
layout (location = 0) in vec3 position; 
layout (location = 1) in vec3 vertexColor;
layout (location = 2) in vec2 textureCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 transform;

void main()
{
    gl_Position = projection* view* model* transform* vec4(position, 1.0); 
}
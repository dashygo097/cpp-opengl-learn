#version 330 core
layout (location = 0) in vec3 position;

out vec3 Coord;

uniform mat4 projection;
uniform mat4 view;

void main()
{
    Coord = position;
    gl_Position = projection * view * vec4(position * 50, 1.0);
}
#version 330 core
layout (location = 0) in vec2 Pos;
layout (location = 1) in vec2 TexCoords;

out vec2 Coord;

void main()
{
    gl_Position = vec4(Pos.x, Pos.y, 0.0f, 1.0f); 
    Coord = TexCoords;
}
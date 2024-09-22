#version 330 core
in vec3 Color;
in vec2 Coord;

out vec4 fragmentColor; 

uniform sampler2D Texture;

void main()
{
    fragmentColor = texture(Texture,Coord) * vec4(Color , 1.0f);
}
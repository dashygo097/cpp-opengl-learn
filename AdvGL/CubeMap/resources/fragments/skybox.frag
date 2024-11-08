#version 330 core
out vec4 fragmentColor;

in vec3 Coord;

uniform samplerCube skybox;

void main()
{    
    fragmentColor = texture(skybox, Coord);
}
#version 330 core
layout (location = 0) in vec3 position; 
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 vertexColor;
layout (location = 3) in vec2 textureCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 transform;

out vec3 Normal;
out vec3 Pos;
out vec3 Color;
out vec2 Coord;

void main()
{
    gl_Position = projection* view* model* transform* vec4(position, 1.0); 
    Normal = normalize(mat3(transpose(inverse(model))) * normal);
    Pos = vec3(model * transform * vec4(position, 1.0f)); 
    Coord = textureCoord;
    Color = vertexColor;
}
#version 330 core
in vec3 Normal;
in vec3 Pos;
in vec3 Color;
in vec2 Coord;

out vec4 fragmentColor;

struct Material
{
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
};

struct Light
{
    float strength;
    vec3 position;
    vec3 color;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform vec3 objectColor;
uniform vec3 viewPos;
uniform Material material;
uniform Light light;


void main()
{


    // Ambient

    vec3 ambient = vec3(texture(material.diffuse, Coord)) * light.color;

    // Diffuse

    vec3 dist_source = light.position - Pos;
    vec3 diff = vec3(texture(material.diffuse, Coord)) * max(0.0f, dot(Normal, normalize(dist_source))); 
    float strength = light.strength / dot(dist_source, dist_source);
    vec3 diffuse = diff * light.color * strength;

    // Specular

    vec3 dist_view = normalize(viewPos - Pos);
    vec3 half_angle = normalize(dist_view + dist_source);
    float spec = max(0.0f, dot(Normal, half_angle));
    vec3 specular = vec3(texture(material.specular, Coord)) * pow(spec, material.shininess) * light.color * strength;

    // Blinn-Phong

    ambient = ambient * light.ambient;
    diffuse = diffuse * light.diffuse;
    specular = specular * light.specular;

    vec3 result = (ambient + diffuse + specular) * objectColor;
    fragmentColor = vec4(result, 1.0f);

}

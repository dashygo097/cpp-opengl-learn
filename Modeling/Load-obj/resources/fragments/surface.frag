#version 330 core
in vec3 Normal;
in vec3 Pos;
in vec2 Coord;

out vec4 fragmentColor;

struct Material
{
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
};

struct myTexture
{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct SpotLight
{
    float strength;
    float cutoff;
    float outercutoff;
    vec3 position;
    vec3 direction;
    vec3 color;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform vec3 objectColor;
uniform vec3 viewPos;
uniform myTexture Texture;
uniform SpotLight light;

vec3 CalcSpotLight(SpotLight light, myTexture texture, vec3 Normal, vec3 viewPos, vec3 objectColor)
{

    // Ambient
    vec3 ambient = texture.ambient * light.color;

    // Diffuse
    vec3 dist_source = light.position - Pos;
    vec3 diff = texture.diffuse * abs(dot(Normal, normalize(dist_source))); 
    float strength = light.strength / dot(dist_source, dist_source);
    float theta = dot(normalize(dist_source), normalize(-light.direction));
    float epsilon = light.cutoff - light.outercutoff;
    float intensity = clamp((theta - light.outercutoff) / epsilon, 0.0f, 1.0f);
    vec3 diffuse = diff * light.color * strength;

    // Specular
    vec3 dist_view = normalize(viewPos - Pos);
    vec3 half_angle = normalize(normalize(dist_view) + normalize(dist_source));
    float spec = abs(dot(Normal, half_angle));
    vec3 specular = texture.specular * pow(spec, texture.shininess) * light.color * strength;

    // Blinn-Phong

    diffuse *= intensity;
    specular *= intensity;

    ambient = ambient * light.ambient;
    diffuse = diffuse * light.diffuse;
    specular = specular * light.specular;

    vec3 result = (ambient + diffuse + specular) * objectColor;
    return result;
}

void main()
{
    vec3 result = CalcSpotLight(light, Texture, Normal, viewPos, objectColor);
    fragmentColor = vec4(result, 1.0f);
}
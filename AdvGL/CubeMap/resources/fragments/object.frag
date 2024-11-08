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

struct DirecLight
{
    float strength;
    vec3 direction;
    vec3 color;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct PointLight
{
    float strength;
    vec3 position;
    vec3 color;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

vec3 CalcPointLight(PointLight light, Material material, vec3 Normal, vec3 viewPos)
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
    vec3 half_angle = normalize(normalize(dist_view) + normalize(dist_source));
    float spec = max(0.0f, dot(Normal, half_angle));
    vec3 specular = vec3(texture(material.specular, Coord)) * pow(spec, material.shininess) * light.color * strength;

    // Blinn-Phong
    ambient = ambient * light.ambient;
    diffuse = diffuse * light.diffuse;
    specular = specular * light.specular;

    vec3 result = (ambient + diffuse + specular);
    return result;
}



vec3 CalcSpotLight(SpotLight light, Material material, vec3 Normal, vec3 viewPos)
{
    // Ambient
    vec3 ambient = vec3(texture(material.diffuse, Coord)) * light.color;

    // Diffuse
    vec3 dist_source = light.position - Pos;
    vec3 diff = vec3(texture(material.diffuse, Coord)) * max(0.0f, dot(Normal, normalize(dist_source))); 
    float strength = light.strength / dot(dist_source, dist_source);
    float theta = dot(normalize(dist_source), normalize(-light.direction));
    float epsilon = light.cutoff - light.outercutoff;
    float intensity = clamp((theta - light.outercutoff) / epsilon, 0.0f, 1.0f);
    vec3 diffuse = diff * light.color * strength;

    // Specular
    vec3 dist_view = normalize(viewPos - Pos);
    vec3 half_angle = normalize(normalize(dist_view) + normalize(dist_source));
    float spec = max(0.0f, dot(Normal, half_angle));
    vec3 specular = vec3(texture(material.specular, Coord)) * pow(spec, material.shininess) * light.color * strength;

    // Blinn-Phong
    diffuse *= intensity;
    specular *= intensity;

    ambient = ambient * light.ambient;
    diffuse = diffuse * light.diffuse;
    specular = specular * light.specular;

    vec3 result = (ambient + diffuse + specular);
    return result;
}

vec3 CalcDirecLight(DirecLight light, Material material, vec3 Normal, vec3 viewPos)
{
    // Ambient
    vec3 ambient = vec3(texture(material.diffuse, Coord)) * light.color;

    // Diffuse
    vec3 diff = vec3(texture(material.diffuse, Coord)) * max(0.0f, dot(Normal, -light.direction)); 
    vec3 diffuse = diff * light.color;

    // Specular
    vec3 dist_view = normalize(viewPos - Pos);
    vec3 half_angle = normalize(normalize(dist_view) + normalize(-light.direction));
    float spec = max(0.0f, dot(Normal, half_angle));
    vec3 specular = vec3(texture(material.specular, Coord)) * pow(spec, material.shininess) * light.color;

    // Blinn-Phong
    ambient = ambient * light.ambient;
    diffuse = diffuse * light.diffuse;
    specular = specular * light.specular;

    vec3 result = (ambient + diffuse + specular);
    return result;
}


vec3 CalcSpotLight(SpotLight light, myTexture texture, vec3 Normal, vec3 viewPos, vec3 objectColor)
{

    // Ambient
    vec3 ambient = texture.ambient * light.color;

    // Diffuse
    vec3 dist_source = light.position - Pos;
    vec3 diff = texture.diffuse * max(0.0f, dot(Normal, normalize(dist_source))); 
    float strength = light.strength / dot(dist_source, dist_source);
    float theta = dot(normalize(dist_source), normalize(-light.direction));
    float epsilon = light.cutoff - light.outercutoff;
    float intensity = clamp((theta - light.outercutoff) / epsilon, 0.0f, 1.0f);
    vec3 diffuse = diff * light.color * strength;

    // Specular
    vec3 dist_view = normalize(viewPos - Pos);
    vec3 half_angle = normalize(normalize(dist_view) + normalize(dist_source));
    float spec = max(0.0f, dot(Normal, half_angle));
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

uniform vec3 objectColor;
uniform vec3 viewPos;
uniform Material material_1;
uniform DirecLight light_1;


void main()
{
    vec3 result = CalcDirecLight(light_1, material_1, Normal, viewPos);
    fragmentColor = vec4(result, 1.0f);
}
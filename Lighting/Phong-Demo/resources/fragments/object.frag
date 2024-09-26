#version 330 core
in vec3 Normal;
in vec3 Pos;

out vec4 Color;

uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 lightColor;
uniform vec3 objectColor;

void main()
{
    // Ambient

    float k_a = 0.1f;
    vec3 ambient = k_a * lightColor;

    // Diffuse

    float k_d = 0.8f;
    vec3 dist_source = normalize(lightPos - Pos);
    float diff = k_d * max(0.0f, dot(Normal, dist_source)); 
    vec3 diffuse = diff * lightColor;

    // Specular

    float k_s = 2.5f;
    int p_ = 16;
    vec3 dist_view = normalize(viewPos - Pos);
    vec3 half_angle = normalize(dist_view + dist_source);
    float spec = max(0.0f, dot(Normal, half_angle));
    vec3 specular = k_s * pow(spec, p_) * lightColor;

    // Blinn-Phong

    vec3 result = (ambient + diffuse + specular) * objectColor;
    Color = vec4(result, 1.0f);

}
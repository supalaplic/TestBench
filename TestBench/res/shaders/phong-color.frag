#version 330 core
out vec4 color;

in vec3 normal;
in vec3 fragPos;
in vec3 lightPos;

uniform vec3 LightColor;

struct Material
{
  vec3 ambient;
  vec3 diffuse;
  vec3 specular;
  float shininess;
};
uniform Material material;


struct Light
{
  vec3 ambient;
  vec3 diffuse;
  vec3 specular;
};
uniform Light light;


void main()
{
  // Ambient
  vec3 ambient = light.ambient * material.ambient;

  // Diffuse
  vec3 norm = normalize(normal);
  vec3 lightDir = normalize(lightPos - fragPos);
  float diff = max(dot(norm, lightDir), 0.0f);
  vec3 diffuse = diff * material.diffuse * light.diffuse;

  // Specular
  vec3 viewDir = normalize(-fragPos);
  vec3 reflectDir = reflect(-lightDir, norm);
  float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess);
  vec3 specular = spec * material.specular * light.specular;

  color = vec4((ambient + diffuse + specular), 1.0f);
}

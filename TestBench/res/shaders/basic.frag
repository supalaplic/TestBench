#version 330 core
out vec4 color;

in vec3 normal;
in vec3 fragPos;
in vec2 texCoords;
in vec3 lightPos;

uniform vec3 LightColor;
uniform sampler2D Texture0;

struct Material
{
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
  vec3 texColor = vec3(texture(Texture0, texCoords));

  // Ambient
  vec3 ambient = light.ambient * texColor;

  // Diffuse
  vec3 norm = normalize(normal);
  vec3 lightDir = normalize(lightPos - fragPos);
  float diff = max(dot(norm, lightDir), 0.0f);
  vec3 diffuse = diff * light.diffuse * texColor;

  // Specular
  vec3 viewDir = normalize(-fragPos);
  vec3 reflectDir = reflect(-lightDir, norm);
  float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess);
  vec3 specular = spec * material.specular * light.specular;

  color = vec4((ambient + diffuse + specular), 1.0f);
}

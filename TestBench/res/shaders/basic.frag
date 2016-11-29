#version 330 core
out vec4 color;

in vec3 normal;
in vec3 fragPos;
in vec3 lightPos;

uniform vec3 ObjectColor;
uniform vec3 LightColor;


void main()
{
  // Ambient
  float ambientStrength = 0.3f;
  vec3 ambient = ambientStrength * LightColor;

  // Diffuse
  vec3 norm = normalize(normal);
  vec3 lightDir = normalize(lightPos - fragPos);
  float diff = max(dot(norm, lightDir), 0.0f);
  vec3 diffuse = diff * LightColor;

  // Specular
  float specularStrength = 0.5f;
  vec3 viewDir = normalize(-fragPos);
  vec3 reflectDir = reflect(-lightDir, norm);
  float spec = pow(max(dot(viewDir, reflectDir), 0.0f), 32);
  vec3 specular = specularStrength * spec * LightColor;

  color = vec4(ObjectColor * (ambient + diffuse + specular), 1.0f);
}

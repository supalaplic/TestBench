#version 330 core
out vec4 color;

in vec3 normal;
in vec3 fragPos;
in vec2 texCoords;
in vec3 lightPos;

uniform vec3 LightColor;
//diffuse
uniform sampler2D Texture0;
//specular
uniform sampler2D Texture1;
//emission
uniform sampler2D Texture2;

struct Material
{
  float shininess;
};
uniform Material material;


struct Light
{
  vec3 direction;

  vec3 ambient;
  vec3 diffuse;
  vec3 specular;

  float constant;
  float linear;
  float quadratic;

  float cutOff;
  float outerCutOff;
};
uniform Light light;


void main()
{
  vec3 texColor = vec3(texture(Texture0, texCoords));


  // Ambient
  vec3 ambient = light.ambient * texColor;
  vec3 lightDir = normalize(lightPos - fragPos);

  //Spot light
  float theta = dot(lightDir, normalize(-light.direction));
  float epsilon = light.cutOff - light.outerCutOff;
  float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);

  // Diffuse
  vec3 norm = normalize(normal);
  float diff = max(dot(norm, lightDir), 0.0f);
  vec3 diffuse = diff * light.diffuse * texColor;

  // Specular
  vec3 viewDir = normalize(-fragPos);
  vec3 reflectDir = reflect(-lightDir, norm);
  float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess);
  vec3 specular = spec * vec3(texture(Texture1, texCoords)) * light.specular;

  //Emission
  //vec3 emission = vec3(texture(Texture2, texCoords));

  //Directional Light
  float distance = length(lightPos - fragPos);
  float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * ( distance * distance));
  color = vec4((ambient + (diffuse + specular) * intensity) * attenuation, 1.0f);


}

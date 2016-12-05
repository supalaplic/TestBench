#version 330 core
out vec4 color;

in vec3 normal;
in vec3 fragPos;
in vec2 texCoords;

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


// struct Light
// {
//   vec3 direction;
//
//   vec3 ambient;
//   vec3 diffuse;
//   vec3 specular;
//
//   float constant;
//   float linear;
//   float quadratic;
//
//   float cutOff;
//   float outerCutOff;
// };
// uniform Light light;


struct DirLight
{
  vec3 direction;

  vec3 ambient;
  vec3 diffuse;
  vec3 specular;
};
uniform DirLight dirLight;

struct PointLight
{
  vec3 position;

  float constant;
  float linear;
  float quadratic;

  vec3 ambient;
  vec3 diffuse;
  vec3 specular;
};

#define NR_POINT_LIGHTS 4
uniform PointLight pointLights[NR_POINT_LIGHTS];

vec3 ComputeDirLight(DirLight light, vec3 normal, vec3 viewDir);
vec3 ComputePointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

vec3 texColor;
vec3 specularColor;

void main()
{
  vec3 norm = normalize(normal);
  vec3 viewDir = normalize(-fragPos);

  texColor = vec3(texture(Texture0, texCoords));
  specularColor = vec3(texture(Texture1, texCoords));

  vec3 result = ComputeDirLight(dirLight, norm, viewDir);
  for(int i = 0;  i < NR_POINT_LIGHTS; i++)
    result += ComputePointLight(pointLights[i], norm, fragPos, viewDir);

  color = vec4(result, 1.0f);
}

vec3 ComputeDirLight(DirLight light, vec3 normal, vec3 viewDir)
{
  vec3 lightDir = normalize(-light.direction);

  //Diffuse
  float diff = max(dot(normal, lightDir), 0.0);
  //Specular
  vec3 reflectDir = reflect(-lightDir, normal);
  float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);

  vec3 ambient = light.ambient * texColor;
  vec3 diffuse = light.diffuse * diff * texColor;
  vec3 specular = light.specular * spec * specularColor;

  return ambient + diffuse + specular;
}

vec3 ComputePointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
  vec3 lightDir = normalize(light.position - fragPos);

  //Diffuse
  float diff = max(dot(normal, lightDir), 0.0);
  //Specular
  vec3 reflectDir = reflect(-lightDir, normal);
  float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);

  //Attenuation
  float distance    = length(light.position - fragPos);
   float attenuation = 1.0f / (light.constant + light.linear * distance +
            light.quadratic * (distance * distance));
   // Combine results
   vec3 ambient  = light.ambient  * texColor;
   vec3 diffuse  = light.diffuse  * diff * texColor;
   vec3 specular = light.specular * spec * specularColor;
   ambient  *= attenuation;
   diffuse  *= attenuation;
   specular *= attenuation;
   return (ambient + diffuse + specular);
}

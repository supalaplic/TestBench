#version 330 core
out vec4 color;

in vec3 normal;
in vec3 fragPos;

uniform vec3 ObjectColor;
uniform vec3 LightColor;
uniform vec3 LightPos;


void main()
{
  float ambientStrength = 0.3f;
  vec3 ambient = ambientStrength * LightColor;

  vec3 norm = normalize(normal);
  vec3 lightDir = normalize(LightPos - fragPos);

  float diff = max(dot(norm, lightDir), 0.0);
  vec3 diffuse = diff * LightColor;

  color = vec4(ObjectColor * (ambient + diffuse), 1.0f);
}

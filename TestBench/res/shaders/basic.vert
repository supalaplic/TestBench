#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;
layout (location = 2) in vec3 normalIn;

out vec3 normal;
out vec3 fragPos;
out vec3 lightPos;

uniform vec3 LightPos;
uniform mat3 Normal;
uniform mat4 Transform;
uniform mat4 ViewModel;
uniform mat4 View;

void main()
{
  gl_Position = Transform * vec4(position, 1.0f);
  fragPos = vec3(ViewModel * vec4(position, 1.0f));
  normal = Normal * normalIn;
  lightPos = vec3(View * vec4(LightPos, 1.0f));
}

#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoordIn;
layout (location = 2) in vec3 normalIn;

out vec3 normal;
out vec3 fragPos;
out vec2 texCoords;

uniform mat3 Normal;
uniform mat4 Transform;
uniform mat4 ViewModel;

void main()
{
  gl_Position = Transform * vec4(position, 1.0f);
  fragPos = vec3(ViewModel * vec4(position, 1.0f));
  normal = Normal * normalIn;
  texCoords = texCoordIn;
}

#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;
layout (location = 2) in vec3 normalIn;

out vec3 normal;
out vec3 fragPos;

uniform mat4 Transform;
uniform mat4 Model;
uniform mat3 Normal;

void main()
{
  gl_Position = Transform * vec4(position, 1.0f);
  fragPos = vec3(Model * vec4(position, 1.0f));
  normal = Normal * normalIn;
}

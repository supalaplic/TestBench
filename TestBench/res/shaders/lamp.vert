#version 330 core
layout (location = 0) in vec3 position;

uniform mat4 Transform;

void main()
{
  gl_Position = Transform * vec4(position, 1.0f);
}

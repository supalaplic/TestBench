#include "shader.h"
#include <fstream>
#include <iostream>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

Shader::Shader(const std::string& filename)
{
	_program = glCreateProgram();
	_shaders[0] = CreateShader(LoadShader(filename + ".vert").c_str(), GL_VERTEX_SHADER);
	_shaders[1] = CreateShader(LoadShader(filename + ".frag").c_str(), GL_FRAGMENT_SHADER);



	for (unsigned int i = 0; i < NUM_SHADERS; i++)
		glAttachShader(_program, _shaders[i]);

	glLinkProgram(_program);
	CheckShaderError(_program, GL_LINK_STATUS, true, "Error: Program linking failed: ");

	glValidateProgram(_program);
	CheckShaderError(_program, GL_VALIDATE_STATUS, true, "Error: Program is invalid: ");
}


Shader::~Shader()
{
	for (unsigned int i = 0; i < NUM_SHADERS; i++)
	{
		glDetachShader(_program, _shaders[i]);
		glDeleteShader(_shaders[i]);
	}

	glDeleteProgram(_program);
}

void Shader::Bind() const
{
	glUseProgram(_program);
}

void Shader::SetUniformMatrix4fv(const std::string& name, GLboolean transpose, const glm::mat4& value) const
{
	auto location = glGetUniformLocation(GetProgram(), name.c_str());
	glUniformMatrix4fv(location, 1, transpose, glm::value_ptr(value));
}

void Shader::SetUniformMatrix3fv(const std::string& name, GLboolean transpose, const glm::mat3& value) const
{
	auto location = glGetUniformLocation(GetProgram(), name.c_str());
	glUniformMatrix3fv(location, 1, transpose, glm::value_ptr(value));
}

void Shader::SetUniform3f(const std::string& name, GLfloat x, GLfloat y, GLfloat z) const
{
	auto location = glGetUniformLocation(GetProgram(), name.c_str());
	glUniform3f(location, x, y, z);
}

void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{

	GLint success;
	GLchar error[512];

	if (isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);

	if (success == GL_FALSE)
	{
		if (isProgram)
			glGetProgramInfoLog(shader, sizeof(error), nullptr, error);
		else
			glGetShaderInfoLog(shader, sizeof(error), nullptr, error);


		std::cerr << errorMessage << ": " << error << std::endl;
	}
}


GLuint CreateShader(const GLchar* text, GLenum shaderType)
{
	auto shader = glCreateShader(shaderType);

	if (shader == 0)
		std::cerr << "Error: Shader creation failed!" << std::endl;

	glShaderSource(shader, 1, &text, nullptr);
	glCompileShader(shader);

	CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader compilation failed: ");

	return shader;
}

static std::string LoadShader(const std::string& fileName)
{
	std::ifstream file;
	file.open(fileName.c_str());

	std::string output;
	std::string line;

	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line);
			output.append(line + "\n");
		}
	}
	else
		std::cerr << "Unable to load shader: " << fileName << std::endl;

	return output;
}

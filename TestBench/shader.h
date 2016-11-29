#pragma once
#include <GL/glew.h>
#include <string>
#include <glm/mat4x2.hpp>

class Shader
{
public:
	Shader(const std::string& filename);
	virtual ~Shader();
	void Bind() const;
	GLuint GetProgram() const { return _program; }
	void SetUniformMatrix4fv(const std::string& name, GLboolean transpose, const glm::mat4& value) const;
	void SetUniformMatrix3fv(const std::string& name, GLboolean transpose, const glm::mat3& value) const;
	void SetUniform3f(const std::string& name, GLfloat x, GLfloat y, GLfloat z) const;
private:
	static const GLuint NUM_SHADERS = 2;
	Shader(const Shader& other) {}
	void operator=(const Shader& other) const {}
	int GetUniforLocation(const std::string& name) const;


	enum
	{
		TRANSFORM_U,

		NUM_UNIFORMS
	};

	GLuint _program;
	GLuint _shaders[NUM_SHADERS];
	GLuint _uniforms[NUM_UNIFORMS];
};

static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
static GLuint CreateShader(const GLchar* text, GLenum shaderType);
static std::string LoadShader(const std::string& fileName);
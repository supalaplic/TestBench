#pragma once
#include <glfw_init.h>
#include <vector>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

struct Vertex
{
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};


class Mesh
{
private:
	std::vector<Vertex> _vertices;
	std::vector<GLuint> _indices;
	GLuint VAO, VBO, EBO;
	GLuint _materialIndex = 0;

public:
	Mesh(const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices);
	void Draw() const;
	virtual ~Mesh();
	void SetMaterialIndex(GLuint materialIndex) { _materialIndex = materialIndex; }
	GLuint GetMaterialIndex() { return _materialIndex; }
private:
	Mesh(const Mesh& other) {}
	void operator=(const Mesh& other) {}
	void SetupMesh();
};


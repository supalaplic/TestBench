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
public:
	Mesh(const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices);
	void Draw() const;
	virtual ~Mesh();
private:
	Mesh(const Mesh& other) {}
	void operator=(const Mesh& other) {}
	void SetupMesh();

	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	GLuint VAO, VBO, EBO;
};


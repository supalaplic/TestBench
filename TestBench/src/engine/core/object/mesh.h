#pragma once
#include "../game_loop.h"
#include <vector>

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


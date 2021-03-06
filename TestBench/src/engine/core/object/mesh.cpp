#include "mesh.h"
#include <vector>


Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices)
{
	this->_vertices = vertices;
	this->_indices = indices;

	SetupMesh();
}


Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &VBO);
}

void Mesh::SetupMesh()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);


	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);


	glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(Vertex), &_vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(GLuint), &_indices[0], GL_STATIC_DRAW);


	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, TexCoords));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, Normal));


	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Mesh::Draw() const
{
	glBindVertexArray(VAO);

	glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
}


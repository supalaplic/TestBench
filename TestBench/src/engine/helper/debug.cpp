#include "debug.h"
#include <glm/gtx/transform.hpp>
#include "camera.h"
#include "../core/resources.h"

#define DEBUG_SHADER "Debug"

std::vector<Debug::Vertex> Debug::_vertices;
bool Debug::_drawInit;
GLuint Debug::VAO, Debug::VBO;

Debug::~Debug()
{
	if (_drawInit)
		glDeleteVertexArrays(1, &VBO);
}

//this is called only once
void Debug::InitializeDraw()
{
	if (_drawInit) return;
	_drawInit = true;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, Color));

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

//draws one vertex for start/end, which is removed after one frame
void Debug::DrawLine(const glm::vec3& start, const glm::vec3& end, const glm::vec3& color)
{
	InitializeDraw();

	//all transform calculations are computed on the CPU so the user can vertices in world coords 
	auto transMatrix = Camera::GetMainCamera()->GetViewProjection() * glm::translate(start);
	//vertex position is (0, 0, 0) so they can be transleted to the given world position
	_vertices.push_back(Vertex{ transMatrix * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), color });

	transMatrix = Camera::GetMainCamera()->GetViewProjection() * glm::translate(end);
	_vertices.push_back(Vertex{ transMatrix * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f), color });
}

//regardless of the number of drawn debug lines, a single draw call/VBO will be used 
void Debug::Draw()
{
	if (!_drawInit || _vertices.size() == 0) return;

	Resources::GetShader(DEBUG_SHADER)->Bind();

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(Vertex), &_vertices[0], GL_DYNAMIC_DRAW);
	glDrawArrays(GL_LINES, 0, _vertices.size());

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	_vertices.clear();
}


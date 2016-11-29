#pragma once
#include "../core/game_loop.h"
#include <vector>
#include <glm/detail/type_vec3.hpp>
#include <glm/detail/type_vec4.hpp>
#include <iostream>

class Debug
{
public:
	//destroy vertex data if anny
	virtual ~Debug();
	static void DrawLine(const glm::vec3& start, const glm::vec3& end, const glm::vec3& color);
	//should only by called by main loop (i need to make it private)
	static void Draw();
	static bool ShouldDraw() { return _drawInit; }

	template<typename T>
	static void Log(const T& log);
	template<typename T>
	static void LogWarning(const T& log);
private:

	//Debug has special Vertex struct as the user can define vertices position to draw lines
	struct Vertex
	{
		//position is vec4 because all transformation computation is done on the CPU
		glm::vec4 Position;
		glm::vec3 Color;
	};

	//Vertex data is initialized only if any debug draw function is called
	static void InitializeDraw();
	static std::vector<Vertex> _vertices;
	static bool _drawInit;
	static GLuint VAO, VBO;
};

template <typename T>
void Debug::Log(const T& log)
{
	std::cout << log << std::endl;
}

template <typename T>
void Debug::LogWarning(const T& log)
{
	std::cout << log << std::endl;
}

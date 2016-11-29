#include <GL/glew.h>
#include "display.h"
#include "mesh.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"
#include "debug.h"
#include "input.h"
#include "time.h"
#include "editor_controller.h"
#include "resources.h"
#include "material.h"
#include "object.h"
#include "cube.h"
#include "lamp.h"
#include "game_loop.h"


int main()
{
	GameLoop gameLoop;
	gameLoop.Loop();
	return 0;

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//Display display(WIDTH, HEIGHT, "CoolGL");
	//Input input(&display);
	//Time time;

	//Camera camera(70.0f, (float)WIDTH / HEIGHT, 0.1f, 100.0f);
	//camera.Transform.SetPos(0.0f, 0.0f, 3.0f);
	//EditorController controller(&display, WIDTH / 2.0, HEIGHT / 2.0);

	//GLfloat data[] = {
	//	//front
	//	-1.0, -1.0, 1.0,  0, 0,   0.0f, 0.0f, 1.0f,
	//	1.0, -1.0, 1.0,   1, 0,   0.0f, 0.0f, 1.0f,
	//	1.0, 1.0, 1.0,    1, 1,   0.0f, 0.0f, 1.0f,
	//	-1.0, 1.0, 1.0,   0, 1,   0.0f, 0.0f, 1.0f,

	//	//right
	//	1.0, 1.0, 1.0,    0, 1,   1.0f, 0.0f, 0.0f,
	//	1.0, 1.0, -1.0,   1, 1,	  1.0f, 0.0f, 0.0f,
	//	1.0, -1.0, -1.0,  1, 0,	  1.0f, 0.0f, 0.0f,
	//	1.0, -1.0, 1.0,   0, 0,	  1.0f, 0.0f, 0.0f,

	//	//back
	//	-1.0, -1.0, -1.0, 0, 0,  0.0f, 0.0f, -1.0f,
	//	1.0, -1.0, -1.0,  1, 0,	 0.0f, 0.0f, -1.0f,
	//	1.0, 1.0, -1.0,   1, 1,	 0.0f, 0.0f, -1.0f,
	//	-1.0, 1.0, -1.0,  0, 1,	 0.0f, 0.0f, -1.0f,

	//	//left
	//	-1.0, -1.0, -1.0, 1, 0,  -1.0f, 0.0f, 0.0f,
	//	-1.0, -1.0, 1.0,  0, 0,	 -1.0f, 0.0f, 0.0f,
	//	-1.0, 1.0, 1.0,   0, 1,	 -1.0f, 0.0f, 0.0f,
	//	-1.0, 1.0, -1.0,  1, 1,	 -1.0f, 0.0f, 0.0f,

	//	//upper
	//	1.0, 1.0, 1.0,    1, 0,  0.0f, 1.0f, 0.0f,
	//	-1.0, 1.0, 1.0,   0, 0,	 0.0f, 1.0f, 0.0f,
	//	-1.0, 1.0, -1.0,  0, 1,	 0.0f, 1.0f, 0.0f,
	//	1.0, 1.0, -1.0,   1, 1,	 0.0f, 1.0f, 0.0f,

	//	//bottom
	//	-1.0, -1.0, -1.0, 0, 1,  0.0f, -1.0f, 0.0f,
	//	1.0, -1.0, -1.0,  1, 1,	 0.0f, -1.0f, 0.0f,
	//	1.0, -1.0, 1.0,   1, 0,	 0.0f, -1.0f, 0.0f,
	//	-1.0, -1.0, 1.0,  0, 0,	 0.0f, -1.0f, 0.0f,
	//};

	//std::vector<GLuint> indices{ 0, 1, 2, 0, 2, 3,
	//							 4, 5, 6, 4, 6, 7,
	//							 8, 9, 10, 8, 10, 11,
	//							 12, 13, 14, 12, 14, 15,
	//							 16, 17, 18, 16, 18, 19,
	//							 20, 21, 22, 20, 22, 23 };

	//glm::vec3 cubePositions[] = {
	//	glm::vec3(0.0f,  0.0f,  0.0f),
	//	glm::vec3(2.0f,  5.0f, -15.0f),
	//	glm::vec3(-1.5f, -2.2f, -2.5f),
	//	glm::vec3(-3.8f, -2.0f, -12.3f),
	//	glm::vec3(2.4f, -0.4f, -3.5f),
	//	glm::vec3(-1.7f,  3.0f, -7.5f),
	//	glm::vec3(1.3f, -2.0f, -2.5f),
	//	glm::vec3(1.5f,  2.0f, -2.5f),
	//	glm::vec3(1.5f,  0.2f, -1.5f),
	//	glm::vec3(-1.3f,  1.0f, -1.5f)
	//};

	//std::vector<Vertex> vertices;
	//for (int i = 0; i < sizeof(data) / sizeof(data[0]); i += 8)
	//{
	//	vertices.push_back(Vertex{ glm::vec3(data[i],  data[i + 1], data[i + 2]), 
	//							   glm::vec3(data[i + 5], data[i + 6], data[i + 7]), 
	//							   glm::vec2(data[i + 3], data[i + 4]) });
	//}

	//auto mesh = Resources::AddMesh("basic_mesh", vertices, indices);
	//auto material = Resources::AddMaterial("basic_mat", "basic_shader", "cube_tex");
	//material->GetTexture()->AddImage("awesome_img");
	//material->GetTexture()->AddImage("container_img");

	//glm::vec3 lightPos(1.2f, 1.0f, 2.0f);


	//std::vector<std::unique_ptr<Object>> objects;
	//for (int i = 0; i < 10; i++)
	//{
	//	auto obj = std::make_unique<Cube>(material, mesh);
	//	obj->GatTransform()->SetScale(glm::vec3(0.5f, 0.5f, 0.5f));
	//	obj->GatTransform()->SetPos(cubePositions[i]);
	//	obj->Index = i;
	//	obj->LightPosition = lightPos;

	//	objects.push_back(std::move(obj));
	//}
	//auto lamp = std::make_unique<Lamp>(Resources::AddMaterial("lamp_mat", "lamp_shader", ""), mesh);
	//lamp->GatTransform()->SetPos(lightPos);
	//lamp->GatTransform()->SetScale(glm::vec3(0.25f, 0.25f, 0.25f));
	//objects.push_back(std::move(lamp));


	//while (!display.ShouldClose())
	//{
	//	display.Clear(0.1f, 0.1f, 0.1f, 1.0f);
	//	time.Update();
	//	input.Update();
	//	controller.Update();

	//	for (int i = 0; i < objects.size(); i++)
	//	{
	//		objects[i]->Update();
	//	}

	//	for (int i = 0; i < objects.size(); i++)
	//	{
	//		objects[i]->Draw(&camera);
	//	}

	//	//debug draws if any
	//	Debug::Draw();
	//	display.Update();
	//}

	//return 0;
}

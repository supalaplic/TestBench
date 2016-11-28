#include "cube.h"
#include "time.h"
#include "debug.h"


Cube::Cube()
{
}

Cube::Cube(Material* material, Mesh* mesh) : Object(material, mesh)
{
}

Cube::~Cube()
{
}

void Cube::Update()
{
	GatTransform()->SetRot(Time::TimeSinceStart() * 20.0f * (Index + 1) * glm::vec3(1.0f, 0.3f, 0.5f));
}

void Cube::Draw(Camera* camera)
{
	material->Bind();
	material->GetShader()->SetUniform3f("ObjectColor", 1.0f, 0.5f, 0.31f);
	material->GetShader()->SetUniform3f("LightColor", 1.0f, 1.0f, 1.0f);
	material->GetShader()->SetUniform3f("LightPos", LightPosition.x, LightPosition.y, LightPosition.z);

	auto model = GatTransform()->GetModel();
	material->GetShader()->SetUniformMatrix4fv("Transform", GL_FALSE, camera->GetViewProjection() * model);
	material->GetShader()->SetUniformMatrix4fv("Model", GL_FALSE, model);
	material->GetShader()->SetUniformMatrix3fv("Normal", GL_TRUE, glm::inverse(model));
	mesh->Draw();
}

#include "cube.h"
#include "../../engine/helper/time.h"


Cube::Cube()
{
}

Cube::Cube(Material* material, Mesh* mesh) : RenderedObject(material, mesh)
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
	material->GetShader()->SetUniform3f("LightPos", LightPosition.x, LightPosition.y, LightPosition.z);
	material->GetShader()->SetUniform1f("material.shininess", 32.0f);

	material->GetShader()->SetUniform3f("light.ambient", 0.2f, 0.2f, 0.2f);
	material->GetShader()->SetUniform3f("light.diffuse", 0.5f, 0.5f, 0.5f);
	material->GetShader()->SetUniform3f("light.specular", 1.0f, 1.0f, 1.0f);


	auto model = GatTransform()->GetModel();
	auto view = camera->GetView();
	auto projection = camera->GetProjection();
	auto viewModel = view * model;
	material->GetShader()->SetUniformMatrix4fv("Transform", GL_FALSE, projection * viewModel);
	material->GetShader()->SetUniformMatrix4fv("ViewModel", GL_FALSE, viewModel);
	material->GetShader()->SetUniformMatrix4fv("View", GL_FALSE, view);
	material->GetShader()->SetUniformMatrix3fv("Normal", GL_TRUE, glm::inverse(viewModel));
	mesh->Draw();
}

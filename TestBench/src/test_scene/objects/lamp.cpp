#include "lamp.h"

Lamp::Lamp(Material * material, Mesh * mesh):RenderedObject(material, mesh)
{
}

void Lamp::Draw(Camera* camera)
{
	material->Bind();
	material->GetShader()->SetUniform3f("Color", Color);
	material->GetShader()->SetUniformMatrix4fv("Transform", GL_FALSE, camera->GetViewProjection() * _transform.GetModel());
	mesh->Draw();
}

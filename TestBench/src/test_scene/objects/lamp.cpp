#include "lamp.h"

void Lamp::AddMesh(Material* material, Mesh* mesh)
{
	RenderedObject::AddMesh(material, mesh);
}

void Lamp::Draw(Camera* camera)
{
	for (auto mesh : _meshes)
	{
		auto material = _materials[mesh->GetMaterialIndex()];
		material->Bind();
		material->GetShader()->SetUniform3f("Color", Color);
		material->GetShader()->SetUniformMatrix4fv("Transform", GL_FALSE, camera->GetViewProjection() * _transform.GetModel());
		mesh->Draw();
	}

}

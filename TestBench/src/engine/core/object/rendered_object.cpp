#include "rendered_object.h"
#include "../game_loop.h"


RenderedObject::RenderedObject()
{
	AddToLoop(GameLoop::LoopType::Draw);
}

void RenderedObject::AddMesh(Material* material, Mesh* mesh)
{
	_materials.push_back(material);
	_meshes.push_back(mesh);
	mesh->SetMaterialIndex(_materials.size() - 1);
}

void RenderedObject::Draw(Camera* camera)
{
	for (auto mesh : _meshes)
	{
		_materials[mesh->GetMaterialIndex()]->Bind();
		_materials[mesh->GetMaterialIndex()]->GetShader()->SetUniformMatrix4fv("Transform", GL_FALSE, camera->GetViewProjection() * _transform.GetModel());
		mesh->Draw();
	}
}

void RenderedObject::ApplyLighting(LightingManager::Mode mode)
{
	switch (mode)
	{
	case LightingManager::OneFull:
		for (auto material : _materials)
			LightingManager::ApplyOneFull(material->GetShader());
		break;
	case LightingManager::OneCapped: break;
	default: break;
	}
}


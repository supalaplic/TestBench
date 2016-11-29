#include "rendered_object.h"
#include "../game_loop.h"


RenderedObject::RenderedObject()
{
	AddToLoop(GameLoop::LoopType::Draw);
}

RenderedObject::RenderedObject(Material* material, Mesh* mesh) :mesh(mesh), material(material)
{
	AddToLoop(GameLoop::LoopType::Draw);
}


void RenderedObject::Draw(Camera* camera)
{
	material->Bind();
	material->GetShader()->SetUniformMatrix4fv("Transform", GL_FALSE, camera->GetViewProjection() * _transform.GetModel());
	mesh->Draw();
}

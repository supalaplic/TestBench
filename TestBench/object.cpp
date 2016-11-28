#include "object.h"


Object::Object(): _transform(Transform())
{
}

Object::Object(Material* material, Mesh* mesh)
{
	Object::material = material;
	Object::mesh = mesh;
}

Object::~Object()
{
}

void Object::Draw(Camera* camera)
{
	material->Bind();
	material->GetShader()->SetUniformMatrix4fv("Transform", GL_FALSE, camera->GetViewProjection() * _transform.GetModel());
	mesh->Draw();
}

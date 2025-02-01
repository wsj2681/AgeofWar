#include "Engine.h"
#include "Object.h"

void Object::Update(const Vector2f& mousePosition)
{

}

void Object::Render(RenderTarget* target)
{
	if (target)
	{
		target->draw(*this);
	}
}

void Object::Init()
{
}

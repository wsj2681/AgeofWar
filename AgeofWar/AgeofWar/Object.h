#pragma once
#include "Engine.h"

class Object : public RectangleShape
{
public:
	Object() = default;
	virtual ~Object() = default;

	virtual void Destroy() = 0;
	// virtual void Update(const float& deltaTime) = 0;
	virtual void Update(const Vector2f& mousePosition);

	virtual void Render(RenderTarget* target);

protected:

private:
	virtual void Init();
};
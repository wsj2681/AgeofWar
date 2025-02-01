#include <iostream>
#include "ButtonObject.h"

ButtonObject::ButtonObject(Color color, Vector2f location)
{
	this->Init(color, location);
}

ButtonObject::~ButtonObject()
{
	Object::~Object();
}

void ButtonObject::Init(Color color, Vector2f location)
{
	this->setPosition(location);
	this->GB = this->getGlobalBounds();
	setSize({ 200.0f, 20.0f });
	setOrigin(GB.width / 2.0f, GB.height / 2.0f);
	setFillColor(color);

	std::cout << "created obj" << std::endl;
}

void ButtonObject::Destroy()
{
}

bool ButtonObject::isClicked(Vector2f mousePoint)
{
	auto GB = this->getGlobalBounds();
	if (GB.contains(mousePoint)) {
		std::cout << "clicked" << std::endl;
		return true;
	}
	std::cout << "unclicked" << std::endl;
	return false;
}

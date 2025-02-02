#include "Object.h"

Object::Object()
{
	setSize(sf::Vector2f(100, 100));
	setFillColor(sf::Color::White);
}

Object::~Object()
{
}

void Object::Update(const float& deltaTime)
{

}

void Object::Update(const sf::Vector2f& mousePosition)
{

}

void Object::Render(sf::RenderWindow* window)
{
	// window->draw(*this);
}

bool Object::isPressed(sf::Vector2f mousePosition)
{
	if (getGlobalBounds().contains(mousePosition) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		return true;
	}
	else
	{
		return false;
	}
}

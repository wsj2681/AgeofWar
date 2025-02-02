#pragma once
#include <SFML/Graphics.hpp>

class Object : public sf::RectangleShape
{
public:

	Object();
	~Object();

	void Update(const float& deltaTime);
	void Update(const sf::Vector2f& mousePosition);
	void Render(sf::RenderWindow* window);

	bool isPressed(sf::Vector2f mousePosition);

private:

};


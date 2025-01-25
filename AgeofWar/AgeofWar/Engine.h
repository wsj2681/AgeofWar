#pragma once

#include <SFML/Graphics.hpp>
#include "Scene.h"

using namespace sf;

class Engine
{
public:
	Engine();
	~Engine();

	void Init();

	void Update();
	void UpdateInput();

	void Render();

private:

	RenderWindow* window = nullptr;

	Event event;

	Clock clock;
	float deltaTime;

	Vector2f mousePosition;

	std::stack<Scene*> scenes;
};


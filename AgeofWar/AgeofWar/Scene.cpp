#include "Scene.h"

Scene::Scene(std::stack<Scene*>* scenes, sf::RenderWindow* window)
{
	this->scenes = scenes;
	this->window = window;
}

void Scene::Render()
{
	for (auto& object : objects)
	{
		window->draw(*object.first);
	}
}

void Scene::EndScene()
{
	this->quit = true;
}

bool Scene::GetQuit()
{
	return quit;
}

Scene::~Scene()
{
	for (auto& object : objects)
	{
		delete object.first;
	}
	objects.clear();
}

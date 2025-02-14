#include "TitleScene.h"
#include "LobbyScene.h"
#include <iostream>

using namespace sf;

TitleScene::TitleScene(std::stack<Scene*>* scenes, sf::RenderWindow* window)
	:Scene(scenes, window)
{
	Init();
}

TitleScene::~TitleScene()
{
	Scene::~Scene();

}

void TitleScene::Init()
{
	auto font = new Font();
	font->loadFromFile("Font/ChosunCentennial_ttf.ttf");
	auto* text = new Text("Title Scene", *font, 50);
	text->setPosition(400, 300);

	objects.push_back({text, "TEXT_object"});

	for (auto& object : objects)
	{
		if (object.second.substr(0, 4) == "TEXT")
		{
			std::cout << "TEXT object Created" << std::endl;
		}
	}

}

void TitleScene::UpdateInput(sf::Event& event)
{
	switch (event.type)
	{
	case Event::MouseButtonPressed:
	{
		Scene* lobbyScene = new LobbyScene(scenes, window);
		scenes->push(lobbyScene);
	}
	default:
		break;
	}
}

void TitleScene::Update(const float& deltaTime)
{
}

void TitleScene::Update(const sf::Vector2f& mousePosition)
{
}

void TitleScene::Render()
{
	Scene::Render();
}

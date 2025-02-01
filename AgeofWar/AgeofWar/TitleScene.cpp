#include "TitleScene.h"
#include "LobbyScene.h"
#include <iostream>
#include <functional>

#define OBJECT_BEHAVIOR_BY_TYPE(x, y, z) if((x).substr(0, (y).size()) == (y)) { z; }
#define OBJECT_BEHAVIOR_BY_NAME(x, y, z) if((x).substr((x).size() - (y).size(), (y).size()) == (y)) { z; }

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
	text->setOrigin(text->getGlobalBounds().width / 2, text->getGlobalBounds().height / 2);
	text->setPosition(window->getSize().x / 2, window->getSize().y / 2);

	objects.push_back({ text, "TEXT_character" });

	auto called = [](const std::string& say)
		{
			std::cout << say << std::endl;
		};

	std::function<void(const std::string)> called2 = [](const std::string& say)
		{
			std::cout << say << std::endl;
		};


	for (auto& object : objects)
	{
		OBJECT_BEHAVIOR_BY_NAME(object.second, std::string("character"), called("OBJECT_BEHAVIOR_BY_NAME called"));
		OBJECT_BEHAVIOR_BY_TYPE(object.second, std::string("TEXT"), called("OBJECT_BEHAVIOR_BY_TYPE called"));
		OBJECT_BEHAVIOR_BY_NAME(object.second, std::string("character"), called2("OBJECT_BEHAVIOR_BY_NAME called2"));
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

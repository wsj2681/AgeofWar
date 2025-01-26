#include "LobbyScene.h"

using namespace sf;

LobbyScene::LobbyScene(std::stack<Scene*>* scenes, sf::RenderWindow* window)
	:Scene(scenes, window)
{
	Init();
}

LobbyScene::~LobbyScene()
{
	Scene::~Scene();
}

void LobbyScene::Init()
{
	auto font = new Font();
	font->loadFromFile("Font/ChosunCentennial_ttf.ttf");
	auto* text = new Text("Lobby Scene", *font, 50);
	text->setPosition(400, 300);

	objects.push_back({text, "TEXT_object"});
}

void LobbyScene::UpdateInput(sf::Event& event)
{
	switch (event.type)
	{
	case Event::KeyPressed:
	{
		if (event.key.code == Keyboard::Escape)
		{
			EndScene();
		}
	}
	default:
		break;
	}
}

void LobbyScene::Update(const float& deltaTime)
{
}

void LobbyScene::Update(const sf::Vector2f& mousePosition)
{
}

void LobbyScene::Render()
{
	Scene::Render();
}

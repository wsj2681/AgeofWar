#include "LobbyScene.h"
#include "ButtonObject.h"

#include <cstdlib>
#include <ctime>

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
	// ButtonObject* btn = new ButtonObject(Color::Blue, {0.0f, 0.0f});
	ButtonObject* btn = new ButtonObject(Color::White, {10.0f, 10.0f});

	auto font = new Font();
	font->loadFromFile("Font/ChosunCentennial_ttf.ttf");
	auto* text = new Text("Lobby Scene", *font, 50);
	text->setPosition(400, 300);

	objects.push_back({text, "TEXT_object"});
	objects.push_back({btn, "BUTTON_object" });
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
	std::string btn_string = "BUTTON_object";
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		for (auto object : objects)
		{
			if (btn_string.compare(object.second) == 0)
			{
				// object.first<ButtonObject>.
			}
		}
	}
}

void LobbyScene::Render()
{
	Scene::Render();
}

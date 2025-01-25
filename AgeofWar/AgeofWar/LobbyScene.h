#pragma once
#include "Scene.h"
class LobbyScene : public Scene
{
public:
	LobbyScene() = delete;
	LobbyScene(std::stack<Scene*>* scenes, sf::RenderWindow* window);
	~LobbyScene();

	void Init() override;
	void UpdateInput(sf::Event& event) override;
	void Update(const float& deltaTime) override;
	void Update(const sf::Vector2f& mousePosition) override;
	void Render() override;
};


#pragma once
#include "Scene.h"
class TitleScene : public Scene
{
public:
	TitleScene() = delete;
	TitleScene(std::stack<Scene*>* scenes, sf::RenderWindow* window);
	~TitleScene();


	void Init() override;
	void UpdateInput(sf::Event& event) override;
	void Update(const float& deltaTime) override;
	void Update(const sf::Vector2f& mousePosition) override;
	void Render() override;
};


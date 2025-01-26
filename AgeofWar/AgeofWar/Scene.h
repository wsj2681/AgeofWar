#pragma once
#include "SFML/Graphics.hpp"
#include <stack>
#include <vector>
#include <string>

class Scene
{
public:
	Scene() = delete;
	Scene(std::stack<Scene*>* scenes, sf::RenderWindow* window);
	
	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;
	Scene(Scene&&) = delete;
	Scene& operator=(Scene&&) = delete;

	virtual ~Scene();

	// Scene 초기화 함수
	virtual void Init() = 0;

	// Scene 입력 처리 함수
	virtual void UpdateInput(sf::Event& event) = 0;
	
	// Scene 업데이트 함수(시간에 따른)
	virtual void Update(const float& deltaTime) = 0;

	// Scene 업데이트 함수(마우스 위치에 따른)
	virtual void Update(const sf::Vector2f& mousePosition) = 0;
	
	// Scene 렌더 함수
	virtual void Render();

	// Scene 종료 함수
	void EndScene();
	bool GetQuit();

protected:

	sf::RenderWindow* window;
	std::stack<Scene*>* scenes;

	// first : Drawable object, second : object name
	std::vector<std::pair<sf::Drawable*, std::string>> objects;

	bool quit = false;

private:

};


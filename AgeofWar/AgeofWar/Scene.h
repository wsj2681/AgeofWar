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

	// Scene �ʱ�ȭ �Լ�
	virtual void Init() = 0;

	// Scene �Է� ó�� �Լ�
	virtual void UpdateInput(sf::Event& event) = 0;
	
	// Scene ������Ʈ �Լ�(�ð��� ����)
	virtual void Update(const float& deltaTime) = 0;

	// Scene ������Ʈ �Լ�(���콺 ��ġ�� ����)
	virtual void Update(const sf::Vector2f& mousePosition) = 0;
	
	// Scene ���� �Լ�
	virtual void Render();

	// Scene ���� �Լ�
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


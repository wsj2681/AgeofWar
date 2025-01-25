#include "Engine.h"
#include "TitleScene.h"

Engine::Engine()
{
	Init();
}

Engine::~Engine()
{
	delete window;
}

void Engine::Init()
{
	window = new RenderWindow(VideoMode(800, 600), "Age of War", Style::Close | Style::Titlebar);
	window->setFramerateLimit(60);
	window->setMouseCursorVisible(true);

	TitleScene* titleScene = new TitleScene(&scenes, window);
	scenes.push(titleScene);

}

void Engine::Update()
{
	deltaTime = clock.getElapsedTime().asSeconds();
	clock.restart();



	mousePosition = Vector2f(Mouse::getPosition(*window));

	UpdateInput();
}

void Engine::UpdateInput()
{
	while (window->pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			window->close();
		}

		switch (event.type)
		{
		case Event::Closed:
		{
			window->close();
			break;
		}
		case Event::KeyPressed:
		case Event::MouseButtonPressed:
		case Event::MouseButtonReleased:
		case Event::MouseMoved:
		case Event::MouseWheelMoved:
		{
			if (!scenes.empty())
			{
				scenes.top()->UpdateInput(event);
			}
			break;
		}
		default:
			break;
		}

	}
}

void Engine::Render()
{
	while (window->isOpen())
	{
		window->clear();

		this->Update();

		if (!scenes.empty())
		{
			scenes.top()->Update(deltaTime);
			scenes.top()->Update(mousePosition);
			scenes.top()->Render();

			if (scenes.top()->GetQuit())
			{
				delete scenes.top();
				scenes.pop();
			}
		}

		window->display();
	}
}

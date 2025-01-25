#include "Engine.h"
#include "TitleScene.h"

namespace aow
{

Engine::Engine() : deltaTime(0.f), elapsedTime(0.f), window(nullptr)
{
    Init();
}

Engine::~Engine()
{
    delete window;
    window = nullptr;
}

void Engine::Init()
{
    window = new RenderWindow(VideoMode(800, 600), "Age of War", Style::Close);
    window->setFramerateLimit(60);

    TitleScene *titleScene = new TitleScene(scenes);
    scenes.push(titleScene);
}

void Engine::Input()
{
    while (window->pollEvent(evt))
    {
        switch (evt.type)
        {
        case Event::KeyPressed:
        case Event::MouseButtonPressed:
        case Event::MouseWheelMoved: {
            // Scene InputUpdate();
            if (!scenes.empty())
            {
                scenes.top()->Input(evt);
            }
            break;
        }
        default:
            break;
        }
    }
}

void Engine::Update()
{
    Vector2f mousePosition = Vector2f(Mouse::getPosition(*window));
    if (!scenes.empty())
    {
        if (scenes.top()->GetQuit())
        {
            scenes.top()->Destroy();
            scenes.top() = nullptr;
            delete scenes.top();
            scenes.pop();
        }
        else
        {
            scenes.top()->Update(deltaTime);
            scenes.top()->Update(mousePosition);
        }
    }
    else
    {
        window->close();
    }
}

int Engine::Render()
{
    while (window->isOpen())
    {
        window->clear();

        Input();
        Update();

        if (!scenes.empty())
        {
            scenes.top()->Render(window);
        }

        window->display();
    }

    return 0;
}

} // namespace aow
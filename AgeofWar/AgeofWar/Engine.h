#pragma once

#include <SFML/Graphics.hpp>
#include <stack>

namespace aow
{
using namespace sf;

class Scene;
class Engine
{
  public:
    Engine();
    ~Engine();

    void Init();

    void Input();
    void Update();

    int Render();

  private:
    RenderWindow *window;
    Event evt;

    Clock clock;

    float deltaTime;
    float elapsedTime;

    Clock engineClock;

    std::stack<Scene *> scenes;
};
} // namespace aow

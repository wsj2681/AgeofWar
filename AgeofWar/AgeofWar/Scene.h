#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <stack>

namespace aow
{
using namespace sf;
class Scene
{
  public:
    Scene();
    Scene(std::stack<Scene *> &scenes);
    virtual ~Scene();

    void EndScene();
    bool GetQuit();

    virtual void Init();
    virtual void Destroy();
    virtual void Update(const Event &evt);
    virtual void Update(const float deltaTime);
    virtual void Update(const Vector2f mousePosition);
    virtual void Input(const Event &evt);
    virtual void Render(RenderWindow *window);
    
  protected:
    std::vector<Drawable *> objects;

    std::stack<Scene *> scenes;
    
    bool quit = false;
};

} // namespace aow

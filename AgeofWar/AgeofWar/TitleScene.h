#pragma once
#include "Scene.h"

namespace aow
{
class TitleScene : public Scene
{
  public:
    TitleScene();
    TitleScene(std::stack<Scene *> &scenes);
    ~TitleScene();
    void Init() override;
    void Update(const Vector2f mousePosition);
    void Update(const float deltaTime) override;
    void Render(RenderWindow *window) override;

};
} // namespace aow
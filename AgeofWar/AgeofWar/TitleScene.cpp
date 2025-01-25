#include "TitleScene.h"

namespace aow
{

TitleScene::TitleScene()
{
    Init();
}

TitleScene::TitleScene(std::stack<Scene *> &scenes)
{
    this->scenes = scenes;
    Init();
}

TitleScene::~TitleScene()
{
    Destroy();
}

void TitleScene::Init()
{
    auto font = new Font();
    font->loadFromFile("Font/ChosunCentennial_ttf.ttf");
    auto title = new Text("Age of War Title Scene", *font, 50);
    title->setPosition(250.f, 250.f);
    objects.push_back(title);
}

void TitleScene::Update(const Vector2f mousePosition)
{
}

void TitleScene::Update(const float deltaTime)
{

}

void TitleScene::Render(RenderWindow *window)
{
    for (auto &obj : objects)
    {
        window->draw(*obj);
    }
}
} // namespace aow
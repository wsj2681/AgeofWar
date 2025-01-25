#include "Scene.h"

namespace aow
{
Scene::Scene()
{
    Init();
}

Scene::Scene(std::stack<Scene *> &scenes)
{
    this->scenes = scenes;
    Init();
}

Scene::~Scene()
{
    Destroy();
}

void Scene::EndScene()
{
    this->quit = true;
}

bool Scene::GetQuit()
{
    return quit;
}

void Scene::Init()
{
}

void Scene::Destroy()
{
}

void Scene::Update(const Event &evt)
{
    
}

void Scene::Update(const float deltaTime)
{
    for (auto &obj : objects)
    {
        // obj->update(deltaTime);
    }
}

void Scene::Update(const Vector2f mousePosition)
{
}

void Scene::Input(const Event &evt)
{

}

void Scene::Render(RenderWindow *window)
{
    for (auto &obj : objects)
    {
        window->draw(*obj);
    }
}

} // namespace aow
#include "Scene.hpp"

ME::SceneManager& ME::SceneManager::Instance()
{
   static SceneManager s;
   return s;
}

void ME::SceneManager::SetScene(std::unique_ptr<ME::Scene> scene)
{
    current_scene = std::move(scene);
}

ME::Scene* ME::SceneManager::GetScene() const {
    return current_scene.get();
}

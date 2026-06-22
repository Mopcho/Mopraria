#include "Engine.hpp"

void ME::Engine::Start()
{
    while (!ME::WindowShouldClose())
    {
        ME::Scene* scene = ME::SceneManager::Instance().GetScene();
        scene->Update();

        BeginDrawing();
            scene->Draw();
            ClearBackground(RAYWHITE);
        EndDrawing();
    }
}
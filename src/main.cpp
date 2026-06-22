#include <iostream>
#include <raylib.h>
#include <iostream>
#include "Textures.hpp"
#include "Block.hpp"
#include "Constants.hpp"
#include "Engine/Window/Window.hpp"
#include "Engine/Scene/Scene.hpp"
#include "Engine/Entity/Entity.hpp"
#include "Engine/AssetsManager/AssetsManager.hpp"

class GameScene : public ME::Scene {
public:
    GameScene() {
        block.transform.width = 100.0f;
        block.transform.height = 100.0f;
        block.transform.position.x = 100.0f;
        assets.LoadTexture("block", (TEXTURES_FOLDER_PATH / "separate/texture_16px 1.png").string());
        block.sprite.texture = assets.GetTexture("block");
        block.sprite.sourceRectangle = Rectangle{0, 0, (float)block.sprite.texture.width, (float)block.sprite.texture.height};
    }

    void Update() {
        block.transform.position.x++;
    }
    void Draw() {
        block.Draw();
    }

    ME::Entity block = ME::Entity();
    ME::AssetsManager assets = ME::AssetsManager();
};

int main() {
    ME::SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    ME::InitWindow(800, 600, "Mopraria");
    ME::MaximizeWindow();

    ME::SceneManager::Instance().SetScene(std::make_unique<GameScene>());

    ME::SetTargetFPS(60);
    while (!ME::WindowShouldClose())
    {
        BeginDrawing();
            ME::Scene* scene = ME::SceneManager::Instance().GetScene();
            scene->Update();
            scene->Draw();
            ClearBackground(RAYWHITE);
        EndDrawing();
    }
    
    ME::CloseWindow();

    return 0;
}
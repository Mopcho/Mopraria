#include <iostream>
#include <raylib.h>
#include <iostream>
#include "Textures.hpp"
#include "Block.hpp"
#include "Constants.hpp"
#include "Engine/Window/Window.hpp"
#include "Engine/Scene/Scene.hpp"

class MenuScene : public ME::Scene {
public:
    MenuScene() {}

    void Update() {
        std::cout << "Update" << std::endl;
    }
    void Draw() {
        std::cout << "Draw" << std::endl;
    }
};

int main() {
    ME::SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    ME::InitWindow(800, 600, "Mopraria");
    ME::MaximizeWindow();

    Textures& textures_instance = Textures::instance();
    textures_instance.load();

    ME::SceneManager::Instance().SetScene(std::make_unique<MenuScene>());

    ME::SetTargetFPS(60);
    while (!ME::WindowShouldClose())
    {
        BeginDrawing();
            ME::Scene* scene = ME::SceneManager::Instance().GetScene();
            scene->Update();
            scene->Draw();
            ClearBackground(RAYWHITE);
            Block block1{Vector2{0, 0}, textures_instance.g_textures[BlockIds::DeepslateBricks]};
            Block block2{Vector2{2, 2}, textures_instance.g_textures[BlockIds::DeepslateBricks]};
            block1.render();
            block2.render();
        EndDrawing();
    }
    
    ME::CloseWindow();

    return 0;
}
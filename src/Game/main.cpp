#include "Constants/constants.hpp"
#include "Engine/Window/Window.hpp"
#include "Engine/Scene/Scene.hpp"
#include "Engine/Entity/Entity.hpp"
#include "Engine/AssetsManager/AssetsManager.hpp"
#include <Engine/Engine/Engine.hpp>
#include <Engine/Animation/Animation.hpp>
#include <Engine/Input/Input.hpp>

class GameScene : public ME::Scene {
public:
    GameScene() {
        player.transform->width = 200.0f;
        player.transform->height = 200.0f;
        player.transform->position.x = 100.0f;
        assets.LoadTexture("player", (TEXTURES_FOLDER_PATH / "Characters/16x16 Idle-Sheet.png").string());
        player.sprite->texture = assets.GetTexture("player");
        player.sprite->sourceRectangle = Rectangle{0, 0, 24.0f, 24.0f};

        animation.SetSprite(player.sprite);
        animation.frames = 4;
        animation.repeat = true;
        animation.animation_speed = 0.3f;
        animation.offset_y = 24;
        animation.Play();
    }

    void Update() {
        if (ME::IsKeyDown(ME::KeyboardKey::KEY_D)) {
            player.transform->position.x += player_speed * ME::GetDeltaTime();
            if (player.sprite->sourceRectangle.width < 0) {
                player.sprite->sourceRectangle.width *= -1;
            }
        } else if (ME::IsKeyDown(ME::KeyboardKey::KEY_A)) {
            player.transform->position.x -= player_speed * ME::GetDeltaTime();
            if (player.sprite->sourceRectangle.width > 0) {
                player.sprite->sourceRectangle.width *= -1;
            }
        }
        animation.Update(ME::GetDeltaTime());
    }

    void Draw() {
        player.Draw();
    }

    ME::Entity player = ME::Entity();
    float player_speed = 100.0f;
    ME::AssetsManager assets = ME::AssetsManager();
    ME::Animation animation = ME::Animation();
};

int main() {
    ME::SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    ME::InitWindow(800, 600, "Mopraria");
    ME::MaximizeWindow();

    ME::SceneManager::Instance().SetScene(std::make_unique<GameScene>());

    ME::SetTargetFPS(60);
    ME::Engine engine;

    // Start game loop
    engine.Start();
    
    ME::CloseWindow();

    return 0;
}
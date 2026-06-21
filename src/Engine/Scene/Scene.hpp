#pragma once
#include <memory>

namespace ME {
    class Scene {
    public:
        virtual ~Scene() = default;
        virtual void Update() = 0;
        virtual void Draw() = 0;
    };

    class SceneManager {
    public:
        static SceneManager& Instance();
        SceneManager(const SceneManager&) = delete;
        SceneManager& operator=(const SceneManager&) = delete;

        void SetScene(std::unique_ptr<Scene> scene);
        ME::Scene* GetScene() const;
    private:
        std::unique_ptr<Scene> current_scene = nullptr;
        SceneManager() = default;
    };
}
cmake_minimum_required(VERSION 4.4)

project(Moprarria CXX)

set(CMAKE_CXX_STANDARD 20)
find_package(raylib CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

add_executable(${PROJECT_NAME} 
        src/main.cpp 
        src/Components/Block.cpp 
        src/Components/Textures.cpp 
        src/Components/Constants.cpp 
        src/Components/Renderable.cpp
        src/Engine/Window/Window.cpp
        src/Engine/Scene/Scene.cpp
        src/Engine/Components/Transform/Transform.cpp
        src/Engine/Components/Sprite/Sprite.cpp
        src/Engine/AssetsManager/AssetsManager.cpp
        src/Engine/Camera/Camera.cpp
        src/Engine/Entity/Entity.cpp
    )
target_include_directories(${PROJECT_NAME} PUBLIC src/Components src/Game src/Engine)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib nlohmann_json::nlohmann_json)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
        ${CMAKE_SOURCE_DIR}/src/Textures
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/Textures
)
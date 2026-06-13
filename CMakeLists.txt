cmake_minimum_required(VERSION 3.5)

project(Moprarria CXX)

set(CMAKE_CXX_STANDARD 20)
find_package(raylib CONFIG REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp src/Components/Block.cpp src/Components/Textures.cpp src/Components/constants.cpp src/Components/Renderable.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC src/Components)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
        ${CMAKE_SOURCE_DIR}/src/Textures
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/Textures
)
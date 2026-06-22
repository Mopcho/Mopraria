#pragma once
#include <filesystem>

std::filesystem::path GetExecutablePath();
inline const std::filesystem::path EXECUTABLE_FOLDER_PATH = GetExecutablePath().parent_path();
inline const std::filesystem::path TEXTURES_FOLDER_PATH = EXECUTABLE_FOLDER_PATH / "Textures";
inline const std::filesystem::path TEXTURES_METADATA_JSON_PATH = TEXTURES_FOLDER_PATH / "metadata.json";

enum BlockIds {
    DeepslateBricks
};
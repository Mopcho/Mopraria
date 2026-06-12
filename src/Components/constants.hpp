#pragma once
#include <filesystem>

std::filesystem::path GetExecutablePath();
inline const std::filesystem::path EXECUTABLE_FOLDER_PATH = GetExecutablePath().parent_path();
inline const std::filesystem::path TEXTURES_FOLDER_PATH = EXECUTABLE_FOLDER_PATH / "Textures";
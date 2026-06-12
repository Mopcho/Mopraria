#pragma once
#include <filesystem>

std::filesystem::path GetExecutablePath();
inline const std::filesystem::path EXECUTABLE_FOLDER_PATH = GetExecutablePath().parent_path();
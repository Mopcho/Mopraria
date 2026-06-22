#include "Constants/constants.hpp"

#ifdef _WIN32
    #include <windows.h>
#elif __linux__
    #include <unistd.h>
    #include <limits.h>
    #include <stdexcept>
#else

#endif

std::filesystem::path GetExecutablePath() {
#ifdef _WIN32
    wchar_t pathBuf[MAX_PATH];
    if (!GetModuleFileNameW(nullptr, pathBuf, MAX_PATH)) {
        throw std::runtime_error("Failed to get executable path");
    }
    return std::filesystem::path(pathBuf);
#elif __linux__
    char buffer[PATH_MAX];

    ssize_t len = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);
    if (len == -1)
    {
        throw std::runtime_error("Failed to get executable path");
    }

    buffer[len] = '\0';

    return std::filesystem::path(buffer);
#else
    throw std::runtime_error("ExecutablePath() not supported on this platform");
#endif
}
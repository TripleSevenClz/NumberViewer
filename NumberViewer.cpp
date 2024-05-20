#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <filesystem>

namespace filesystem = std::filesystem;

int main()
{
    wchar_t runningDirectroyStr[MAX_PATH];
    ::GetModuleFileName(nullptr, runningDirectroyStr, MAX_PATH);
    filesystem::path runningDirectroy(runningDirectroyStr);
    runningDirectroy = runningDirectroy.parent_path();

    std::cout << "运行目录：" << runningDirectroy << std::endl;

    std::ifstream trainImages(runningDirectroy / "train-images.idx3-ubyte");
    std::ifstream trainLables(runningDirectroy / "train-labels.idx1-ubyte");


}

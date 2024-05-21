#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <filesystem>
#include <cassert>

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

    int amount;
    {
        int n;
        trainImages >> n;
        assert(n == 2051);

        trainLables >> n;
        assert(n == 2049);

        trainImages >> n;
        trainLables >> n;
        amount = n;

        std::cout << "已打开训练集，共" << n << "个样本。" << std::endl;
    }

    for (int i = 0; i < amount; i++)
    {
        trainImages >> 
    }
}

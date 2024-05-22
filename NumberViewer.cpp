#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <filesystem>
#include <cassert>
#include <winsock.h>

#define readUI(input, n) trainImages.read(reinterpret_cast<char*>(&n), sizeof(n)); n = ntohl(n);

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
	assert(trainImages.is_open());
	assert(trainLables.is_open());

	int amount;
	{
		int n;
		readUI(trainImages, n);
		std::cout << n;
		assert(n == 2051);

		readUI(trainImages, n);
		assert(n == 2049);

		readUI(trainImages, n);
		readUI(trainLables, n);
		amount = n;

		std::cout << "已打开训练集，共" << n << "个样本。" << std::endl;
	}

	struct
	{
		int x;
		int y;
	} size;
	{
		readUI(trainImages, size.x);
		readUI(trainImages, size.y);

		std::cout << "训练集图像尺寸：" << size.x << "*" << size.y << "。" << std::endl;
	}

	unsigned char pixel;
	for (int i = 0; i < amount; i++)
	{
		for (int x = 0; x < size.x; x++)
		{
			for (int y = 0; y < size.y; y++)
			{
				readUI(trainImages, pixel);
				std::cout << pixel << " ";
			}
			std::cout << std::endl;
		}
		break;
	}
}

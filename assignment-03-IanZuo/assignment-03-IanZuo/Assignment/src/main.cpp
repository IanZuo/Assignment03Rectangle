#define SDL_MAIN_HANDLED
#include "SDL.h"
#include <iostream>
#include <cstdlib>  // atoi()
#include "../include/Application.h"

int main(int argc, char* argv[]) {
    int numRectangles = 5;  // 默认值

    // 检查命令行参数
    if (argc > 1) {
        int inputNum = std::atoi(argv[1]);  // 将输入转换为整数
        if (inputNum > 0) {
            numRectangles = inputNum;  // 更新矩形数量
        } else {
            std::cerr << "Invalid number of rectangles. Using default: " << numRectangles << std::endl;
        }
    }

    std::cout << "Starting application with " << numRectangles << " rectangles." << std::endl;

    Application app(numRectangles);

    if (!app.Init()) {
        std::cerr << "Failed to initialize SDL2 application!" << std::endl;
        return -1;
    }

    app.Run();
    app.Cleanup();

    return 0;
}

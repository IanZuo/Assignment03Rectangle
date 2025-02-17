#define SDL_MAIN_HANDLED
#include "SDL.h"
#include <iostream>
#include "../include/Application.h"

// Entry point of the program
int main(int argc, char* argv[]) {
    // Create an Application instance with 5 rectangles
    Application app(5);

    // Initialize SDL2
    if (!app.Init()) {
        std::cerr << "Failed to initialize SDL2 application!" << std::endl;
        return -1;
    }

    // Run the main loop
    app.Run();

    // Cleanup SDL2 resources
    app.Cleanup();

    return 0;
}

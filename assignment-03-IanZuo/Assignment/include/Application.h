#ifndef APPLICATION_H
#define APPLICATION_H

#include "SDL.h"
#include <vector>
#include "../include/Rectangle.h"

// Main application class to manage SDL2 window, events, and rendering
class Application {
public:
    Application(int numRects);  // Constructor
    ~Application();  // Destructor

    bool Init();  // Initialize SDL2
    void Run();  // Run the main loop
    void Cleanup();  // Cleanup SDL2 resources

private:
    void HandleEvents();  // Handle user input (events)
    void Update();  // Update game logic (move rectangles)
    void Render();  // Render objects to the screen

    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;
    std::vector<Rectangle> rectangles;  // List of rectangles
    int windowWidth = 800;
    int windowHeight = 600;
};

#endif

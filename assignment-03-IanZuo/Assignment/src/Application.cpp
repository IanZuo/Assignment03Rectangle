#include "../include/Application.h"
#include <iostream>
#include <cstdlib>  // For random numbers

// Constructor: Initialize rectangles with random positions and speeds
Application::Application(int numRects)
    : window(nullptr), renderer(nullptr), isRunning(false) {
    rectangles.reserve(numRects);
    for (int i = 0; i < numRects; ++i) {
        int x = rand() % (windowWidth - 50);
        int y = rand() % (windowHeight - 50);
        int dx = (rand() % 5) + 1;
        int dy = (rand() % 5) + 1;
        rectangles.emplace_back(x, y, 50, 50, dx, dy);
    }
}

// Destructor: Cleanup resources
Application::~Application() {
    Cleanup();
}

// Initialize SDL2 (Window and Renderer)
bool Application::Init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("Moving Rectangles",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              windowWidth, windowHeight, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return false;
    }

    isRunning = true;
    return true;
}

// Handle user input events (quit event)
void Application::HandleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
    }
}

// Update logic: Move all rectangles
void Application::Update() {
    for (auto& rect : rectangles) {
        rect.Move(windowWidth, windowHeight);
    }
}

// Render background and rectangles
void Application::Render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Set background color to black
    SDL_RenderClear(renderer);

    for (const auto& rect : rectangles) {
        rect.Draw(renderer);  // Draw each rectangle
    }

    SDL_RenderPresent(renderer);  // Display everything on the screen
}

// Cleanup SDL2 resources
void Application::Cleanup() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
    if (window) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    SDL_Quit();
}
// Run the main application loop
void Application::Run() {
    while (isRunning) {
        HandleEvents();  // Process user input (e.g., quit event)
        Update();        // Move rectangles
        Render();        // Draw everything

        // Limit frame rate (optional but recommended)
        SDL_Delay(16);  // ~60 FPS (1000 ms / 60 frames ≈ 16 ms per frame)
    }
}


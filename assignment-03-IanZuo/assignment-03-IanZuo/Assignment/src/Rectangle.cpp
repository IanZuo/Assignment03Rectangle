#include "../include/Rectangle.h"

// Constructor: Initialize position, size, and speed
Rectangle::Rectangle(int x, int y, int w, int h, int dx, int dy)
    : x(x), y(y), w(w), h(h), dx(dx), dy(dy) {}

// Move the rectangle, bouncing when hitting screen edges
void Rectangle::Move(int windowWidth, int windowHeight) {
    x += dx;
    y += dy;

    // Bounce off the left/right edges
    if (x <= 0 || x + w >= windowWidth) {
        dx = -dx;
    }

    // Bounce off the top/bottom edges
    if (y <= 0 || y + h >= windowHeight) {
        dy = -dy;
    }
}

// Draw the rectangle on screen
void Rectangle::Draw(SDL_Renderer* renderer) const {
    SDL_Rect rect = { x, y, w, h };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // Set color to white
    SDL_RenderFillRect(renderer, &rect);
}

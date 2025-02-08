#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SDL2/SDL.h>

class Rectangle {
public:
    Rectangle(int x, int y, int w, int h, int dx, int dy);
    void Move(int windowWidth, int windowHeight);
    void Draw(SDL_Renderer* renderer) const;

private:
    int x, y, w, h;
    int dx, dy; // 速度 (X 方向, Y 方向)
};

#endif

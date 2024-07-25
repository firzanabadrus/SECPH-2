#include <graphics.h>

#include "shape.hpp"
#include "rect.hpp"

Rect::Rect(int _x, int _y, int _width, int _height) : Shape(_x,_y), width(_width), height(_height) {}

void Rect::draw() const
{
    setcolor(selected ? YELLOW : WHITE);
    rectangle(x, y, x + width, y + height);
}

void Rect::undraw() const
{
    setcolor(BLACK);
    rectangle(x, y, x + width, y + height);
}

void Rect::resize(double scale)
{
    undraw();
    width *= scale;
    height *= scale;
    draw();
}

bool Rect::isMouseClick(int mx, int my) const
{
    int x2 = x + width;
    int y2 = y + height;

    return (x <= mx) && (mx <= x2) && (y <= my) && (my <= y2);
}


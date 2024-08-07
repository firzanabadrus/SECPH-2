#include <graphics.h>
#include<cmath>

#include "shape.hpp"
#include "circle.hpp"

Circle::Circle(int _x, int _y, int _radius): Shape(_x,_y) , radius(_radius){}

void Circle::draw() const
{
    setcolor(selected ? YELLOW : WHITE);
    circle(x, y, radius);
}

void Circle::undraw() const
{
    setcolor(BLACK);
    circle(x, y, radius);
}

void Circle::resize(double scale)
{
    undraw();
    radius *= scale;
    draw();
}

bool Circle::isMouseClick(int mx, int my) const
{
    int d ;
    d = sqrt(pow(mx-x, 2) + pow(my-y, 2));

    return d <= radius;
}



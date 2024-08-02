#include "point.hpp"

Point::Point(int x, int y):_x(x), _y(y) {}

void Point::move(int x, int y)
{
    _x = x;
    _y = y; 
}
int Point::x() const 
{
    return _x;
}

int Point::y() const 
{
    return _y;
}
void Point::setX(int x)
{
    _x = x;
}

void Point::setY(int y)
{
    _y = y;
}
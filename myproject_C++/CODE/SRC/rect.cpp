#include "rect.hpp"

Rect::Rect(int w, int h) : _w(w), _h(h), _pos(0, 0) {}
Rect::Rect(int w, int h, Point pos) : _w(w), _h(h), _pos(pos) {}

void Rect::draw(const Color &color)
{
    for (int i = 0; i < _h; i++)
    {
        for (int j = 0; j < _w; j++)
        {
            Screen::instance()->draw_point(Point(j+_pos.x(), i+_pos.y()), color);
        }
    }
}
void Rect::setWidth(int w)
{
    _w = w;
}
void Rect::setHeight(int h)
{
    _h = h;
}
int Rect::w() const
{
    return _w;
}
int Rect::h() const
{
    return _h;
}

void Rect::resize(int w, int h)
{
    _w = w;
    _h = h;
}
void Rect::move(int x, int y)
{
    this->_pos.move(x, y);
}

Point Rect::get_beginxy() const
{
    Point p(_pos.x(),_pos.y());
    return p;
}
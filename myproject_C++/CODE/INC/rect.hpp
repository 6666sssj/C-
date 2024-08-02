#ifndef RECT_HPP
#define RECT_HPP

#include "screen.hpp"
#include "point.hpp"
#include "color.hpp"

class Rect
{
public:
    Rect() = default;
    Rect(int w, int h);
    Rect(int w, int h, Point pos);
    void draw(const Color &color);
    void setWidth(int w);
    void setHeight(int h);
    int w() const;
    int h() const;

    void resize(int w, int h);
    void move(int x, int y);
    //获取绘制起始点坐标
    Point get_beginxy() const;
private:
    int _w;
    int _h;
    Point _pos;
};

#endif
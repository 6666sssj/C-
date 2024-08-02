#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "point.hpp"
#include "color.hpp"

class Screen
{
public:
    static Screen* instance();
    ~Screen();
    void draw_point(int x, int y, int color);
    void draw_point(Point pos, Color color);
    
private:
    Screen(const char* name);
    Screen(const Screen& ) = delete;
    Screen& operator=(const Screen&) = delete;
    const char* _name;
    int _w;
    int _h;
    short _bpp;
    int _fd;
    int* _addr;
};

#endif


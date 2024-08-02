#include "screen.hpp"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <iostream>
using namespace std;

Screen* Screen::instance()
{
    static Screen s("/dev/fb0");
    //static Screen s("/dev/ubuntu_lcd");
    return &s;
}


Screen::Screen(const char *name)
{
    _name = name;
    _w = 800;
    _h = 480;
    _bpp = 32;
    _fd = ::open(name, O_RDWR);
    if (_fd == -1)
    {
        perror("open screen error");
        exit(1);
    }
    _addr = (int*)mmap(NULL, _w * _h * _bpp / 8, PROT_READ | PROT_WRITE, MAP_SHARED, _fd, 0);
    if (_addr == MAP_FAILED)
    {
        perror("mmap error");
        exit(1);
    }
    cout << "open screen success!" << endl;
}
Screen::~Screen()
{
    munmap(_addr, _w * _h * _bpp / 8);
    ::close(_fd);
}
void Screen::draw_point(int x, int y, int color)
{
    if (x >= 0 and x < _w and y >= 0 and y < _h)
    {
        *(_addr + _w*y + x) = color;
    }
}
void Screen::draw_point(Point pos, Color color)
{
    draw_point(pos.x(), pos.y(), color.value());
}
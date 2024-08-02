#ifndef __BITMAP_HPP
#define __BITMAP_HPP

#include "Screen.hpp"
class bitmap
{
public:
    bitmap(const char* filename);
    ~bitmap();
    void draw(int x = 0, int y = 0);
private:
    int bmp_fd;
    const char* _filename;
    int _width;
    int _height;
    short _depth;

};





#endif
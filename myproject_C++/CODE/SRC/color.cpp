#include "color.hpp"

Color::Color(int r, int g, int b):_red(r), _green(g), _blue(b) {}

int Color::value() const
{
    return (_red<<16 | _green<<8 | _blue);
}
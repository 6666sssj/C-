#ifndef __DRAW_SNAKE_HPP
#define __DRAW_SNAKE_HPP

#include "map.hpp"

class draw_snake : public Map
{
private:
    const char *_head;
    const char *_body;
    const char *_food;
    const char *_fail;
    const char *_body1;
public:
    draw_snake();

    void draw_point(int i, int j, const char *part);

    void draw_head(Point p);

    void draw_body(Point p);

    void draw_body1(Point p);

    void draw_food(Point p);

    void draw_fail(Point p);
};

#endif
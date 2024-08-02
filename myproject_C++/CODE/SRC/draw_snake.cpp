#include "draw_snake.hpp"
#include <iostream>
draw_snake::draw_snake() : _head("./red.bmp"), _body("./green.bmp"), _food("./meat.bmp"),_fail("./fail.bmp"),_body1("./bule.bmp")
{
    draw();
}

void draw_snake:: draw_point(int i, int j, const char *part)
{
    bitmap b(part);
    b.draw(get_cells()[i * get_cols() + j].get_beginxy().x(), get_cells()[i * get_cols() + j].get_beginxy().y());
}
void draw_snake::draw_head(Point p)
{
    draw_point(p.x(), p.y(), _head);
}
void draw_snake::draw_body(Point p)
{
    draw_point(p.x(), p.y(), _body);
}
void draw_snake::draw_body1(Point p)
{
    draw_point(p.x(), p.y(), _body1);
}
void draw_snake::draw_food(Point p)
{
    draw_point(p.x(), p.y(), _food);
}

void draw_snake::draw_fail(Point p)
{
    draw_point(p.x(), p.y(), _fail);
}

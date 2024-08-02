#ifndef __snake_node_HPP
#define __snake_node_HPP

#include <memory>
#include <deque>
#include "point.hpp"
#include "draw_snake.hpp"
#include <iostream>
#include <unistd.h>

#include <algorithm>

#include <random>
#include <ctime>

using namespace std;

class snake_node
{
private:
    Point _current;
    Point _prev;

public:
    snake_node(Point cur, Point prev) : _current(cur), _prev(prev) {}

    void set_current(Point p)
    {
        _current.move(p.x(), p.y());
    }
    void set_prev(Point p)
    {
        _prev.move(p.x(), p.y());
    }
    Point get_current() const
    {
        return _current;
    }
    Point get_prev() const
    {
        return _prev;
    }
};

class motion
{
public:
    motion(int direction = 2);
    void run();
    bool move(int direction = 2);
    bool move_penetrable(int direction = 2);
    int getSnakeSize() const;
    Point generate_random_food();
private:
    int _direction;  //移动方向，给move传的参数
    std::deque<snake_node> a; //定义的队列，存储蛇的各个节点
    Point last_point;         //保存每次移动前的蛇的尾巴节点
    Point _food;                //食物的坐标（行数列数）
    draw_snake test1;       //实例化draw_snake类
};



#endif // __snake_node_HPP

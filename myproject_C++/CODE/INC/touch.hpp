#ifndef __TOUCH_HPP
#define __TOUCh_HPP

#include <linux/input.h>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fcntl.h>
#include "point.hpp"



class touch
{
private:
    int touch_fd;
    Point xy;
    std::string _device;
    struct input_event ev;
public:
    touch();
    ~touch();
    bool getTouchCoordinate(int &x, int &y);
};






#endif
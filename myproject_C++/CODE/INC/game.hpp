#ifndef GAME_HPP
#define GAME_HPP

#include "color.hpp"
#include "map.hpp"
#include "bitmap.hpp"
#include "touch.hpp"
#include "motion.hpp"
#include <thread>
#include <mutex>


class Game
{
public:
    Game();
    ~Game();
    void run(bool model);
    void gettouch();
private:
    motion *mo;
    int x;
    int y;
    int direction;
    touch *ts; 
    bool pluse;
    bool model;//可穿墙和不可穿墙
    std::mutex touch_mutex;
};

#endif
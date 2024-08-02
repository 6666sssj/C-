#include "game.hpp"
#include "screen.hpp"
#include <chrono>

Game::Game() : pluse(1), model(0)
{
    // _map = new Map;
    // _logo = new bitmap("./images/logo.bmp");
    mo = new motion;
    ts = new touch;
}

Game::~Game()
{
    // delete _map;
    delete mo;
    delete ts;
}


void Game::run(bool model)
{
    x = -1;
    y = -1;
    std::thread touch_thread = std::thread(&Game::gettouch, this);
    touch_thread.detach();

    // 游戏主循环
    while (true)
    {
        if (pluse)
        {
            if (x > 700 && x < 800 && y > 50 && y < 100)
            {
                if (direction != 4)
                    direction = 3;
                // lock_direction = 0;
            }
            if (x > 700 && x < 800 && y > 100 && y < 150)
            {
                if (direction != 3)
                    direction = 4;
            }
            if (x > 700 && x < 800 && y > 150 && y < 200)
            {
                if (direction != 1)
                    direction = 2;
            }
            if (x > 700 && x < 800 && y > 200 && y < 250)
            {
                if (direction != 2)
                    direction = 1;
            }
            if (model == 1)
            {
                if (mo->move_penetrable(direction) == false)
                {
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                    break;
                }
            }
            else
            {
                if (mo->move(direction) == false)
                {
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                    break;
                }
            }
            mo->run();
            int time = (mo->getSnakeSize() < 10) ? mo->getSnakeSize() : 10;
            std::this_thread::sleep_for(std::chrono::milliseconds(500 - 35*time));
        }
        if (x > 700 && x < 800 && y > 300 && y < 345)
        {
            pluse = 1;
        }
        if (x > 700 && x < 800 && y > 355 && y < 400)
        {
            pluse = 0;
        }
        if (x > 710 && x < 790 && y > 410 && y < 440)
        {
            break;
        }
    }
}

void Game::gettouch()
{

    while (true)
    {
        if (ts->getTouchCoordinate(x, y))
        {
            std::cout << "Touch coordinates: (" << x << ", " << y << ")" << std::endl;
        }
        else
        {
            std::cerr << "Failed to get touch coordinates." << std::endl;
            break;
        }
    }
}
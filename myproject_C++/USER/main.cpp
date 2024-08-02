#include "game.hpp"
#include "draw_snake.hpp"
#include "motion.hpp"


int main(int argc, char const *argv[])
{
    bitmap b("./main.bmp");
    while (1)
    {
        b.draw();

        touch ts;
        int x = -1;
        int y = -1;
        ts.getTouchCoordinate(x, y);
        Game game;
        if (x > 125 && x < 270 && y > 315 && y < 370)
        {
            game.run(1);
            x = -1;
            y = -1;
        }
        if (x > 480 && x < 680 && y > 315 && y < 370)
        {
            game.run(0);
            x = -1;
            y = -1;
        }
    }

    return 0;
}

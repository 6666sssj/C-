#include "touch.hpp"

touch::touch() :touch_fd(-1), _device("/dev/input/event0")
{
    touch_fd = open(_device.c_str(), O_RDONLY);
    if (touch_fd < 0)
    {
        std::cerr << "Failed to open touch device: " << _device << std::endl;
    }
}

touch::~touch()
{
    if (touch_fd >= 0)
    {
        close(touch_fd);
    }
}

bool touch::getTouchCoordinate(int &x, int &y)
{
    if (touch_fd < 0)
    {
        return false;
    }

    struct input_event ev;
    bool flag_x = false, flag_y = false;

    while (true)
    {
        int res = read(touch_fd, &ev, sizeof(ev));
        if (res != sizeof(ev))
        {
            continue;
        }

        if (ev.type == EV_ABS)
        {
            if (ev.code == ABS_X)
            {
                x = static_cast<int>(ev.value * 800.0 / 1040);
                flag_x = true;
            }
            else if (ev.code == ABS_Y)
            {
                y = static_cast<int>(ev.value * 480.0 / 600);
                flag_y = true;
            }
        }

        if (flag_x && flag_y)
        {
            break;
        }
    }
    return true;
}


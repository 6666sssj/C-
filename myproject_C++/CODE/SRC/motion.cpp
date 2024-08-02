#include "motion.hpp"

motion ::motion(int direction) : _direction(direction)
{
    _food = generate_random_food();
    test1.draw_food(_food);
    snake_node _head_node(Point(8, 8), Point(8, 9));
    snake_node _second_node(Point(8, 7), Point(8, 8));
    snake_node _third_node(Point(8, 6), Point(8, 7));
    a.push_back(_head_node);
    a.push_back(_second_node);
    a.push_back(_third_node);
}

void motion::run()
{

    test1.draw_cell(last_point);

    for (auto it = a.begin(); it != a.end(); ++it)
    {
        if (it == a.begin())
        {
            test1.draw_head(it->get_current());
        }
        else
        {
            if (a.size() <= 7)
            {
                test1.draw_body(it->get_current());
            }
            else
            {
                test1.draw_body1(it->get_current());
            }
        }
    }
}

bool motion::move(int direction)
{
    last_point = a.back().get_current();          // 保存蛇尾节点的当前位置
    Point new_head_pos = a.front().get_current(); // 获取当前头部节点的位置

    switch (direction)
    {
    case 1: // 向左移动
        new_head_pos.move(new_head_pos.x(), new_head_pos.y() - 1);
        break;
    case 2: // 向右移动
        new_head_pos.move(new_head_pos.x(), new_head_pos.y() + 1);
        break;
    case 3: // 向上移动
        new_head_pos.move(new_head_pos.x() - 1, new_head_pos.y());
        break;
    case 4: // 向下移动
        new_head_pos.move(new_head_pos.x() + 1, new_head_pos.y());
        break;
    }
    if (new_head_pos.x() < 0 || new_head_pos.x() >= test1.get_rows() || new_head_pos.y() < 0 || new_head_pos.y() >= test1.get_cols())
    {
        test1.draw_fail(Point(12, 12));
        return false;
    }
    for (size_t i = a.size() - 1; i > 0; --i)
    {
        a[i].set_prev(a[i].get_current());        // 设置当前节点的前一个位置为当前位置
        a[i].set_current(a[i - 1].get_current()); // 将当前节点的位置更新为前一个节点的位置
    }

    a[0].set_prev(a[0].get_current()); // 设置头部节点的前一个位置为当前位置

    a[0].set_current(new_head_pos); // 更新头部节点的位置为新的头部位置

    if (a.front().get_current() == _food)
    {
        snake_node new_node(last_point, last_point); // 这里创建的新节点的前一个位置和当前节点的位置相同
        a.push_back(new_node);                       // 将新节点添加到蛇的尾部

        do
        {
            _food = generate_random_food();
        } while (std::find_if(a.begin(), a.end(), [this](const snake_node &node)
                              { return node.get_current() == _food; }) != a.end());
        test1.draw_food(_food);
    }
    return true;
}

bool motion::move_penetrable(int direction)
{
    last_point = a.back().get_current();          // 保存蛇尾节点的当前位置
    Point new_head_pos = a.front().get_current(); // 获取当前头部节点的位置

    switch (direction)
    {
    case 1: // 向左移动
        new_head_pos.move(new_head_pos.x(), new_head_pos.y() - 1);
        break;
    case 2: // 向右移动
        new_head_pos.move(new_head_pos.x(), new_head_pos.y() + 1);
        break;
    case 3: // 向上移动
        new_head_pos.move(new_head_pos.x() - 1, new_head_pos.y());
        break;
    case 4: // 向下移动
        new_head_pos.move(new_head_pos.x() + 1, new_head_pos.y());
        break;
    }
    if (new_head_pos.x() < 0 || new_head_pos.x() >= test1.get_rows() || new_head_pos.y() < 0 || new_head_pos.y() >= test1.get_cols())
    {
        if (new_head_pos.x() < 0)
        {
            new_head_pos.setX(test1.get_rows() - 1);
        }
        if (new_head_pos.x() >= test1.get_rows())
        {
            new_head_pos.setX(0);
        }
        if (new_head_pos.y() < 0)
        {
            new_head_pos.setY(test1.get_cols() - 1);
        }
        if (new_head_pos.y() >= test1.get_cols())
        {
            new_head_pos.setY(0);
        }
    }
    for (size_t i = a.size() - 1; i > 0; --i)
    {
        a[i].set_prev(a[i].get_current());        // 设置当前节点的前一个位置为当前位置
        a[i].set_current(a[i - 1].get_current()); // 将当前节点的位置更新为前一个节点的位置
    }

    a[0].set_prev(a[0].get_current()); // 设置头部节点的前一个位置为当前位置

    a[0].set_current(new_head_pos); // 更新头部节点的位置为新的头部位置

    for (auto it = a.begin() + 3; it != a.end(); ++it)
    {
        if (it->get_current() == a.front().get_current())
        {
            test1.draw_fail(Point(12, 12));
            return false;
        }
    }

    if (a.front().get_current() == _food)
    {
        snake_node new_node(last_point, last_point); // 这里创建的新节点的前一个位置和当前节点的位置相同
        a.push_back(new_node);                       // 将新节点添加到蛇的尾部

        do
        {
            _food = generate_random_food();
        } while (std::find_if(a.begin(), a.end(), [this](const snake_node &node)
                              { return node.get_current() == _food; }) != a.end());
        test1.draw_food(_food);
    }
    return true;
}

int motion::getSnakeSize() const
{
    return a.size() - 3;
}

Point motion::generate_random_food()
{
    // static std::mt19937 rng(std::time(nullptr)); // 随机数生成器，使用当前时间作为种子
    // std::uniform_int_distribution<int> dist_x(3, 43 - 1); // X 坐标范围
    // std::uniform_int_distribution<int> dist_y(3, 30 - 1); // Y 坐标范围

    // int x = dist_x(rng); // 生成随机 X 坐标
    // int y = dist_y(rng); // 生成随机 Y 坐标
    // 设置随机种子
    std::srand(static_cast<unsigned>(std::time(0)));

    int min_x = 1; // 指定最小范围
    int min_y = 1;
    int max_y = 42; // 指定最大范围
    int max_x = 29;
    // 生成范围[min, max]内的随机整数
    int random_number_x = min_x + std::rand() % (max_x - min_x + 1);
    int random_number_y = min_x + std::rand() % (max_y - min_y + 1);
    _food.move(random_number_x, random_number_y);
    return _food; // 返回生成的随机食物位置
}

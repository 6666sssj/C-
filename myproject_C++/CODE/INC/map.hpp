
/**
 * @brief 游戏地图类
 * 
 */
#ifndef MAP_HPP
#define MAP_HPP

#include "rect.hpp"
#include "color.hpp"
#include "bitmap.hpp"

class Map
{
public:
    Map();
    ~Map();
    void draw();
    //获取创建的数组指针
    Rect* get_cells() const;
    //获取设置的大矩形的列数
    int get_cols() const;
     //获取设置的大矩形的列数
    int get_rows() const;

    //绘制某个格子（传坐标），使其成为初始化时的颜色，用来覆盖蛇的末尾节点
    void draw_cell(Point p);
private:
    int _rows;
    int _cols;
    int _cell_size;
    int _gap_size;
    Rect *_cells;
    Color _cell_color;
};


#endif

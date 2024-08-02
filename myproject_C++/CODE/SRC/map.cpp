#include "map.hpp"
#include <iostream>

Map::Map() : _rows(30), _cols(43), _cell_size(15), _gap_size(1), _cell_color(255,255,255)
{
   
    _cells = new Rect[_rows * _cols];
    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _cols; j++)
        {
            _cells[i * _cols + j].resize(_cell_size, _cell_size);
            _cells[i * _cols + j].move(j * (_cell_size + _gap_size), i * (_cell_size + _gap_size));
        }
    }
}
Map::~Map()
{
    delete [] _cells;

}
Rect* Map::get_cells() const
{
    return _cells;
}
int Map::get_cols() const
{
    return _cols;
}
int Map::get_rows() const
{
    return _rows;
}
void Map::draw()
{
     //初始化界面为纯黑色
    Rect init_black(800,480);
    init_black.draw(Color(000,000,000));
    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _cols; j++)
        {
            _cells[i * _cols + j].draw(_cell_color);
        }
    }
    //显示玩家控制界面
    bitmap bain("./bian.bmp");
    bain.draw(700,0);
}

void Map::draw_cell(Point p)
{
    _cells[p.x()*_cols+p.y()].draw(_cell_color);
}
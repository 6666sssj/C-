#ifndef POINT_HPP
#define POINT_HPP
// Point类的声明
class Point
{
public:
    Point(int x=0, int y=0);
    void move(int x, int y);
    int x() const;
    int y() const;
    void setX(int x);
    void setY(int y);
    bool operator==(const Point& other) const { return _x == other._x && _y == other._y; }
    bool operator!=(const Point& other) const { return _x!=other._x || _y!= other._y;}
private:
    int _x;
    int _y;
};

#endif
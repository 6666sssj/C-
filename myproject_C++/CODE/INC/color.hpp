#ifndef COLOR_HPP
#define COLOR_HPP

class Color
{
public:
    Color(int r, int g, int b);

    /**
     * @brief 把颜色的三个分量，组成一个32位的整数值
     * 
     */
    int value() const;
private:
    int _red;
    int _green;
    int _blue;
};

#endif
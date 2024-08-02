#include "screen.hpp"
#include "bitmap.hpp"
#include <stdio.h>
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdexcept>

using namespace std;


bitmap::bitmap(const char* filename): _filename(filename) 
{
    //1.open打开图片文件
    bmp_fd = open(_filename, O_RDONLY);
    if(-1 == bmp_fd)
        throw std::logic_error("open file error");
        char bm[2] = {0};
    read(bmp_fd, bm, 2);
    if (bm[0] != 'B' || bm[1] != 'M')
         throw std::logic_error("this is not a bmpmap");
      //2.解析图片宽、高、色深
    //解析宽
    lseek(bmp_fd, 0x12, SEEK_SET);	
    read(bmp_fd, &_width, 4);
    //解析高
    lseek(bmp_fd, 0x16, SEEK_SET);
    read(bmp_fd, &_height, 4);
    //解析色深
    lseek(bmp_fd, 0x1C, SEEK_SET);
    read(bmp_fd, &_depth, 2);
}
bitmap::~bitmap()
{
    close(bmp_fd);
}

void bitmap::draw(int _x ,int _y)
{
    
    //3.获取像素数组的数据
    //计算像素数组的大小
    int line_effective_bytes = abs(_width) * (_depth/8); //一行的有效字节数
    int laizi = 0; //一行的赖子数
    int line_total_bytes = 0; //一行的总字节数
    int piexl_array_bytes = 0; //整个像素数组的字节数
    if(line_effective_bytes % 4 != 0) //证明会有填充字节
    {
        laizi = 4 - line_effective_bytes % 4;
    }
    line_total_bytes = laizi + line_effective_bytes;
    piexl_array_bytes = line_total_bytes * abs(_height); //abs(),求绝对值

    //把像素数据全部从图片文件中读取出来
    unsigned char piexl_arr[piexl_array_bytes]; 
    lseek(bmp_fd, 0x36, SEEK_SET);
    read(bmp_fd, piexl_arr, piexl_array_bytes);  

    //4.解析像素数组中的数据，得到一个一个的像素点显示到LCD屏幕对应的位置
    int a,r,g,b;
    int k=0; //遍历piexl_arr数组
    int color;

    for(int j=0; j<abs(_height); j++) 
    {
        for(int i=0; i<abs(_width); i++) //循环1次把该行的所有像素点显示了  //2
        {
            b = piexl_arr[k++];
            g = piexl_arr[k++];
            r = piexl_arr[k++];
            if(_depth == 32)
            {
                a = piexl_arr[k++];
            }
            else
            {
                a = 0;
            }
            color = a<<24 | r<<16 | g<<8 | b; //得到了一个颜色值（像素点）
            //把获取到的像素点显示开发板上对应位置上
            int x = _width>0 ? i : abs(_width)-1-i;
            int y = _height>0 ? abs(_height)-1-j : j;
            // if(color != 0x00FFFFFF)
            // {
                Screen::instance()->draw_point(x+_x,y+_y,color);
           // }
            
        }
        
        k += laizi; //跳过每一行后面的癞子数目
    }
}

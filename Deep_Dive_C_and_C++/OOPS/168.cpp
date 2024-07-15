#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Rectangle
{
private:
    int length; ///--- use 4 bytes
    int width;  ///--- use 4 bytes

public:
    //--- parameterize constructor(沒帶參數就是non-parameterize constructor)
    Rectangle(int l = 1, int w = 1)
    {

        //--- 可以使用accessors來驗證構造函數參數的合理性
        setLength(l);
        setWidth(w);
    }

    //--- copy constructor
    Rectangle(Rectangle &r)
    {
        length = r.length;
        width = r.width;
    }

    void setLength(int l)
    {
        if (l > 0)
            length = l;
        else
            length = 0;
    }

    void setWidth(int w)
    {
        if (w > 0)
            width = w;
        else
            width = 0;
    }

    int getLength()
    {
        return length;
    }

    int getWidth()
    {
        return width;
    }

    int area()
    {
        return width * length;
    }

    int perimeter()
    {
        return 2 * (length + width);
    }
};

int main(void)
{

    Rectangle *p = new Rectangle(10, 5);

    Rectangle r1(10, 5);
    Rectangle r2(r1);

    printf("area is %d\n", p->area());
    printf("area of r2 is %d\n", r2.area());
    return 0;
}
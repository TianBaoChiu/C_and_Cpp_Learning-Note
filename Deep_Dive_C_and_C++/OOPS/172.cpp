#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Rectangle
{
private:
    int length;
    int width;

public:
    Rectangle();
    Rectangle(int l, int w);
    Rectangle(Rectangle &r);

    int getLength();
    int getWidth();

    void setLength(int l);
    void setWidth(int w);

    int area();
    int perimeter();

    bool isSquare();

    ~Rectangle();
};
int main(void)
{

    Rectangle r1(10, 5);

    printf("area is %d\n", r1.area());

    return 0;
}

Rectangle::Rectangle()
{
    length = 1;
    width = 1;
}

Rectangle::Rectangle(int l = 1, int w = 1)
{

    //--- 可以使用accessors來驗證構造函數參數的合理性
    setLength(l);
    setWidth(w);
}

//--- copy constructor
Rectangle::Rectangle(Rectangle &r)
{
    length = r.length;
    width = r.width;
}

void Rectangle::setLength(int l)
{
    if (l > 0)
        length = l;
    else
        length = 0;
}

void Rectangle::setWidth(int w)
{
    if (w > 0)
        width = w;
    else
        width = 0;
}

int Rectangle::getLength()
{
    return length;
}

int Rectangle::getWidth()
{
    return width;
}

int Rectangle::area()
{
    return width * length;
}

int Rectangle::perimeter()
{
    return 2 * (length + width);
}

bool Rectangle::isSquare()
{
    return length == width;
}

Rectangle::~Rectangle()
{
    printf("Destructor\n");
}
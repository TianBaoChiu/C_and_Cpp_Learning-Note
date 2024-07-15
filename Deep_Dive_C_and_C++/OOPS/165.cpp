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

    Rectangle *p = new Rectangle();

    //--- using mutators
    p->setLength(10);
    p->setWidth(5);

    printf("area is %d\n", p->area());

    //--- using accessors
    printf("width is %d\n", p->getWidth());
    printf("Length is %d\n", p->getLength());

    return 0;
}
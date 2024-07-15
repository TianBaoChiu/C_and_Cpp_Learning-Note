#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Rectangle
{
public:
    int length; ///--- use 4 bytes
    int width;  ///--- use 4 bytes

    int area()
    {
        return width * length;
    }
};

int main(void)
{
    Rectangle r1;

    //--- 使用.去訪問實例中的資訊
    r1.length = 6;
    r1.width = 5;

    int area = r1.area();
    int size = sizeof(r1);
    printf("area = %d\n", area);
    printf("size = %d\n", size);

    return 0;
}
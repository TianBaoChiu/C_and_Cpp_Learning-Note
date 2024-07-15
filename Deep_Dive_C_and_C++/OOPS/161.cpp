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

    int perimeter()
    {
        return 2 * (length + width);
    }
};

int main(void)
{

    Rectangle r;  //--- 在stack當中建立一個物件(4bytes)
    Rectangle *p; //--- 在stack當中建議一個指針(8bytes)

    //--- 儘管 Rectangle()沒有被定義，但是c++編譯器會默認一個構造函數
    Rectangle *q = new Rectangle(); //--- q是一個指針 指向一個在heap當中的物件

    p = &r; //--- 將指針p指向r

    r.length = 10; //--- 存取stack當中的物件使用 "."

    p->length = 10; //--- 存取指針指向的物件要用箭頭 "->"
    p->width = 5;

    q->length = 10;
    q->width = 5;

    printf("object in stack area is %d\n", p->area());
    printf("object in heap area is %d\n", q->area());
    return 0;
}
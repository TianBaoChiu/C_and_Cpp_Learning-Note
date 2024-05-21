#include <iostream>
using namespace std;

int main()
{
    // 在stack中建立一個指針，然後指向透過new在heap中建立的記憶體地址
    // 注意在heap當中建立的記憶體是可以被更改大小的，其實也就是將指針指向一個新的記憶體空間
    // 但有著不同的大小
    int *p = new int[5];

    p[0] = 12;
    p[1] = 13;

    cout << p[1] << endl;

    // 使用new的話要注意，記得釋放記憶體並且清空值向heap的指針
    // 在將指針指向其他大小的記憶體地址時，也要記得先清空原本的地址內的東西
    delete[] p;
    p = nullptr;

    return 0;
}
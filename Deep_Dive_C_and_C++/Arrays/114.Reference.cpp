#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    int &y = x;

    cout << x << endl;
    x++;
    y++;

    cout << x << endl;

    // y和x共用同一個地址
    cout << &y << endl;
    cout << &x << endl;
    return 0;
}
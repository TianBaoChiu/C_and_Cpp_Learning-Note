#include <iostream>
using namespace std;

int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    int *p = A;

    // 打印出A陣列的第一格的位置(值等於1的位置)
    // 0x61fef8 0x61fef9 0x61fefa 0x61fefb
    cout << p << endl;

    // 打印出第二格的位置，因為int是4個byte，所以地址會+4
    // 0x61fefc 0x61fefd 0x61fefe 0x61feff
    cout << p + 1 << endl;
}
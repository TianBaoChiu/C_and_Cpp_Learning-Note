#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void)
{
    // 在heap當中創建一個大小為5的整數陣列，並用p指向他
    int *p = new int[5];
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", p[i]); // 1 2 3 4 5
    }

    printf("\n");

    // 在heap當中創建一個大小更大的array
    int *q = new int[10];

    printf("%u\n", q);

    // 把值由p放到複製到q當中，可以適用memcpy
    memcpy(q, p, 5 * sizeof(int));

    // 把原本p指向的整數陣列刪除
    delete[] p;

    // 把p指向當前的q，並且將q指向一個空指針;
    p = q;
    q = nullptr;

    printf("%u\n", p);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", p[i]); // 1 2 3 4 5
    }

    return 0;
}
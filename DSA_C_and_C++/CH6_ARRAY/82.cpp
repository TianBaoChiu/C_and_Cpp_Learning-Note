#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void)
{
    int A[5] = {1, 2, 3, 4, 5};
    int *p;
    p = new int[5];
    p[0] = 6;
    p[1] = 7;
    p[2] = 8;
    p[3] = 9;
    p[4] = 10;

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    for (int j = 0; j < 5; j++)
    {
        printf("%d ", p[j]);
    }
    printf("\n");

    printf("%d\n", sizeof(A));  // 4 * 5 = 20
    printf("%d\n", sizeof(*p)); // pointer is 8(64) or 4(32)

    return 0;
}
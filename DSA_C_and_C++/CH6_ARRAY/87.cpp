#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void)
{
    // 一般方式宣告陣列
    int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    // 使用stack當中的指針指向heap當中的陣列
    int *B[3];

    B[0] = new int[3];
    B[1] = new int[3];
    B[2] = new int[3];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    // 使用雙指針
    int **C;

    C = new int *[3];
    C[0] = new int[3];
    C[1] = new int[3];
    C[2] = new int[3];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    delete[] *B;
    delete[] *C;

    unsigned int x[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    printf("%u,%u, %u", x + 3, (x + 3), (x + 2) + 3);
    return 0;
}
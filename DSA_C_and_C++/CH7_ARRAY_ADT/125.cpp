#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void)
{
    int A[] = {1, 2, 2, 2, 3, 4, 5, 6, 6, 6, 6, 6, 7, 8, 8, 8, 9};
    int length = sizeof(A) / sizeof(A[0]);
    int h = 9;
    int l = 1;

    int H[h] = {0};

    for (int i = 0; i < length; i++)
    {
        H[A[i]] += 1;
    }
    for (int i = l; i < h; i++)
    {
        if (H[i] > 1)
            printf("Duplicate num %d show %d times\n", i, H[i]);
    }

    return 0;
}
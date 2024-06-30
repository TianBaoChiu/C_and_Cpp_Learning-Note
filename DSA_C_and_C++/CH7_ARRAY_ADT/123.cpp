#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void)
{
    int A[] = {3, 6, 5, 7, 9, 8, 1};
    int length = sizeof(A) / sizeof(A[0]);

    int h = 9;
    int l = 1;
    //---Bit set
    int H[h + 1] = {0};

    for (int i = 0; i < length; i++)
    {
        H[A[i]] = 1;
    }

    //--- use bit set to find out missing element
    for (int i = l; i <= h; i++)
    {
        if (H[i] == 0)
            printf("missing num %d\n", i);
    }
    return 0;
}
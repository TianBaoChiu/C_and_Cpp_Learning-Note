#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//--- finding more than one missing element in an array
int main(void)
{

    int A[] = {2, 3, 4, 5, 7, 8, 9, 12, 13, 14, 15};

    int length = sizeof(A) / sizeof(A[0]);

    int diff = A[0];
    for (int i = 0; i < length; i++)
    {
        if (A[i] - i != diff)
        {
            while (diff < A[i] - i)
            {
                printf("miss num is %d\n", diff + i);
                diff++;
            }
        }
    }
    return 0;
}
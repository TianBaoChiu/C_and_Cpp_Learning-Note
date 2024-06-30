#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void)
{

    int A[] = {1, 2, 2, 2, 3, 4, 5, 6, 6, 6, 6, 6, 7, 8, 8, 8, 9};
    int length = sizeof(A) / sizeof(A[0]);
    int last_duplicate = 0;

    for (int i = 0; i < length; i++)
    {
        if (A[i] == A[i + 1] && A[i] != last_duplicate)
        {
            printf("Duplicate number is %d\n", A[i]);
            last_duplicate = A[i];
        }
    }
    return 0;
}
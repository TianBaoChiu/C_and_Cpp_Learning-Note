#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int find_max_num(int *A, int length)
{
    int max_value = A[0];

    for (int i = 0; i < length; i++)
    {
        if (A[i] > max_value)
            max_value = A[i];
    }
    return max_value;
}

void finding_pair_num(int *A, int k, int length)
{
    int max_num;
    max_num = find_max_num(A, length);

    int H[max_num + 1] = {0}; //--- total length = 0 + max_num

    for (int i = 0; i < length; i++)
    {
        if (H[k - A[i]] == 1)
            printf("%d + %d = %d\n", k - A[i], A[i], k);
        H[A[i]] = 1;
    }
}

int main(void)
{

    int A[] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    int length = sizeof(A) / sizeof(A[0]);

    int k = 10;
    finding_pair_num(A, k, length);

    return 0;
}
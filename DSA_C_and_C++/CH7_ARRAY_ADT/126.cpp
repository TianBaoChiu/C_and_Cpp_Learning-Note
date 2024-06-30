#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int find_max_value(int *A, int length)
{
    int max_value = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] > max_value)
            max_value = A[i];
    }
    return max_value;
}
void function1(int *A, int length)
{

    int count;

    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] != -1)
        {
            count = 1;
            for (int j = i + 1; j < length; j++)
            {
                if (A[i] == A[j])
                {
                    count++;
                    A[j] = -1;
                }
            }
            if (count > 1)
                printf("number %d duplicate %d times\n", A[i], count);
        }
    }
}

void function2(int *A, int length)
{
    int max_value = find_max_value(A, length);
    int H[max_value + 1] = {0};

    for (int i = 0; i < length; i++)
    {
        H[A[i]] += 1;
    }

    for (int i = 0; i <= max_value; i++)
    {
        if (H[i] > 1)
            printf("number %d duplicate %d times\n", i, H[i]);
    }
}

int main(void)
{

    int A[] = {8, 8, 9, 6, 9, 2, 5, 5, 4, 3, 2, 9, 5, 8, 9, 2, 1};
    int length = sizeof(A) / sizeof(A[0]);
    // function1(A, length);
    function2(A, length);

    return 0;
}
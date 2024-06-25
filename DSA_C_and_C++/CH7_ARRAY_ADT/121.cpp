#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//--- finding missing element in an array
int main(void)
{
    int A[] = {1, 2, 3, 4, 5, 7, 8, 9, 10, 11};

    int length = sizeof(A) / sizeof(A[0]);

    printf("Length is = %d\n", length);

    int sum = 0;
    int true_sum;

    for (int i = 0; i < length; i++)
        sum = sum + A[i];
    true_sum = A[length - 1] * (A[length - 1] + 1) / 2;
    printf("sum = %d\n", sum);
    printf("true_sum = %d\n", true_sum);

    int missing_num = true_sum - sum;
    printf("missing num is %d\n", missing_num);
    return 0;
}
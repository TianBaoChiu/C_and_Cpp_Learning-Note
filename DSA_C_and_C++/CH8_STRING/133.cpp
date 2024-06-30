#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void)
{

    char A[] = "welcome";
    int i;

    for (i = 0; A[i] != '\0'; i++)
    {
        A[i] = A[i] - 32; //--- lower to upper
    }
    printf("%s\n", A);

    for (i = 0; A[i] != '\0'; i++)
    {
        A[i] = A[i] + 32; //--- upper to lower
    }
    printf("%s\n", A);
    return 0;
}
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void)
{

    char A[] = "Welcome";
    int i;
    printf("%s\n", A);

    for (i = 0; A[i] != '\0'; i++)
    {
        printf("%c\n", A[i]);
    }
    printf("String length is %d\n", i);

    return 0;
}
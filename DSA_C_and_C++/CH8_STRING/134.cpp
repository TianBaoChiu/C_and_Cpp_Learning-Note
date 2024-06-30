#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void)
{

    char A[] = "How are you";
    int word = 1;
    printf("%s\n", A);

    for (int i = 0; A[i] != '\0'; i++)
    {
        if (A[i] == ' ' && A[i - 1] != ' ')
            word++;
    }

    printf("Total word is %d\n", word);

    return 0;
}
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void Reverse_function1(char *A)
{
    int i;
    for (i = 0; A[i] != '\0'; i++) //--- 將字串開頭的指針移動到字尾
    {
    }
    i = i - 1; //--- 不要'\n'
    printf("%c\n", A[i]);

    char B[i + 1];
    int j;

    for (j = 0; i >= 0; j++, i--)
    {
        B[j] = A[i];
    }
    B[j] = '\n';
    printf("%s\n", B);
}

void Reverse_function2(char *A)
{
    int i, j;
    char temp;
    for (j = 0; A[j] != '\0'; j++) //--- 將字串開頭的指針移動到字尾
    {
    }
    j = j - 1; //--- 不要'\n'，此時j指向string在'\0'前的位置

    for (i = 0; i < j; i++, j--)
    {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    printf("%s\n", A);
}

int main(void)
{

    char A[] = "python";

    // Reverse_function1(A);
    Reverse_function2(A);

    return 0;
}
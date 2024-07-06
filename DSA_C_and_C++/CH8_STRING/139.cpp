#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void)
{
    char A[] = "finding";
    //--- 因為字母小寫有26個，我們預計使用32bits來紀錄，儘管會多出幾個
    //--- 沒有用到的位元，但這是無法避免的
    long int H = 0; //--- 4 bytes = 32 bits
    long int x = 0; // 用來當mask
    printf("%d\n", sizeof(H));

    for (int i = 0; A[i] != '\0'; i++)
    {
        x = 1;
        x = x << (A[i] - 97); //--- shift x

        if ((x & H) > 0)
            printf("%c is duplicate\n", A[i]); //--- 如果這個位置有東西了，mask後會是1
        else
            H = x | H; //--- 沒有東西，那就用or去改這個bit
    }

    return 0;
}
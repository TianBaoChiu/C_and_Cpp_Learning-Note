#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void)
{

    int A[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
    {
        printf("%u\n", &A[i]);
        // 每個int占用4個bytes
        // 6422280 6422284 6422288 6422292 6422296
    }

    return 0;
}
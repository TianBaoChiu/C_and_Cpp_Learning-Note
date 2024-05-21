#include <iostream>
using namespace std;

int main()
{
    int A[3][2] = {{1, 2}, {3, 4}, {5, 6}};

    int B[2][3] = {1, 2, 3, 4, 5, 6};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << A[i][j];
        }
        cout << endl;
    }

    // 二維數組使用for each時，可用auto來取得data type
    // 或是int(&x)[3]也可
    for (int(&x)[3] : B)
    {
        for (int &y : x)
        {
            cout << y;
        }
        cout << endl;
    }

    return 0;
}
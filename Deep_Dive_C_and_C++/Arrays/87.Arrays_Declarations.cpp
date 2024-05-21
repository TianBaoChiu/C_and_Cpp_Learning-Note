#include <iostream>
using namespace std;

int main()
{
    // 給定大小和值
    int A[5] = {3, 5, 9, 15, 12};
    // 沒給大小，但有給值
    int B[] = {6, 5, 10};
    // 給了大小，剩下沒給值的地方會自動補0
    int C[6] = {2, 2};
    for (int i = 0; i < 5; i++)
    {
        cout << A[i] << endl;
    }
    for (int i = 0; i < 3; i++)
    {
        cout << B[i] << endl;
    }

    // 此種寫法於C++11中加入
    for (int x : C)
    {
        cout << x << endl;
    }

    return 0;
}
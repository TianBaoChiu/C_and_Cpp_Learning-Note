#include <iostream>
using namespace std;

int main()
{
    int A[7] = {4, 8, 6, 9, 5, 2, 7};

    int max_num = 0;

    for (int x : A)
    {
        if (x > max_num)
        {
            max_num = x;
        }
    }

    cout << max_num << endl;
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int A[10] = {1, 2, 3, 7, 8, 9, 11, 22, 33, 44};
    int key;

    cout << "Enter a key" << endl;
    cin >> key;

    // 線性搜尋
    for (int i = 0; i < 10; i++)
    {
        if (A[i] == key)
        {
            cout << "Find the key at :" << i << endl;
            return 0;
        }
    }
    cout << "Key not exist...";

    return 0;
}
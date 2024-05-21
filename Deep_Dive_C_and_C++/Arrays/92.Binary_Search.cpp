#include <iostream>
using namespace std;

int main(void)
{
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    int key;
    int mid;
    int l = 0, h = 10;

    cout << "Input the key";
    cin >> key;
    while (l <= h)
    {

        mid = (l + h) / 2;
        if (A[mid] == key)
        {
            cout << "Find the key : " << mid;
            return 0;
        }
        else if (A[mid] > key)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << "No key";
    return 0;
}
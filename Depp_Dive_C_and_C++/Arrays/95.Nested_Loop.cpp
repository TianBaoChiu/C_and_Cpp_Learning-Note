#include <iostream>
using namespace std;

int main(void)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << "(" << i << "," << j << ")";
        }
        cout << endl;
    }
    return 0;
}
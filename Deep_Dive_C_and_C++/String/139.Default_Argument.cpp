#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int add(int a, int b, int c = 0)
{
    return a + b + c;
}

int main(void)
{
    int sum = 0;

    //--- 不去填入c的值，將會使用預設值
    sum = add(5, 6);

    cout << "sum = " << sum << endl;

    return 0;
}
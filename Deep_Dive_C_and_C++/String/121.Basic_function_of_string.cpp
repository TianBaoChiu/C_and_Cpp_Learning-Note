#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "Hello";

    cout << str.length() << endl;

    cout << str.size() << endl;

    cout << str.capacity() << endl;

    return 0;
}
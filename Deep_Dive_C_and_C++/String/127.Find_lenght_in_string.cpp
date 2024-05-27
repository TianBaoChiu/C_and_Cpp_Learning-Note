#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void)
{
    string s;
    int string_index = 0;

    cout << "Input a string:";
    getline(cin, s);

    while (s[string_index] != '\0')
    {
        cout << s[string_index] << endl;
        string_index++;
    }

    cout << "The Length of string is: " << string_index << endl;

    return 0;
}
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void)
{
    string s;

    getline(cin, s);
    int string_length = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        string_length += 1;
    }
    string s_rev(string_length, '_');
    cout << "string_length = " << string_length << endl;
    cout << "s = " << s << endl;

    for (int i = 0; i < string_length; i++)
    {
        s_rev[i] = s[string_length - i - 1];
        cout << s_rev[i] << endl;
        cout << s[string_length - i] << endl;
    }

    s_rev += "\0";

    cout << "s_rev = " << s_rev << endl;

    if (s == s_rev)
        cout << "Is palindrome";
    else
        cout << "Is not palindrome";

    return 0;
}
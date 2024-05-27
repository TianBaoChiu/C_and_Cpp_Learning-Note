#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define UPPER true

int main(void)
{
    string s;
#if UPPER
    int ascii_index = -32;
    int min = 97;
    int max = 122;
#else
    int ascii_index = 32;
    int min = 65;
    int max = 90;
#endif

    getline(cin, s);

    cout << s << endl;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= min && s[i] <= max)
        {
            s[i] = s[i] + ascii_index;
        }
    }

    cout << s << endl;

    return 0;
}
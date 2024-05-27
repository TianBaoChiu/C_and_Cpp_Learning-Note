#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void)
{
    string s;
    int vowels_num = 0;     //--- 元音
    int consonants_num = 0; //--- 輔音
    int word_num = 0;
    int current_char = 0;
    int shift_index = 1;
    getline(cin, s);

    // 跳過開頭的所有連續空白
    while (s[current_char] == ' ')
    {
        current_char++;
    }

    while (s[current_char] != '\0')
    {
        //--- 找尋大小寫母音
        if (s[current_char] == 'A' || s[current_char] == 'E' || s[current_char] == 'I' || s[current_char] == 'O' || s[current_char] == 'U' ||
            s[current_char] == 'a' || s[current_char] == 'e' || s[current_char] == 'i' || s[current_char] == 'o' || s[current_char] == 'u')
        {
            vowels_num += 1;
            current_char += 1;
        }
        //--- 遇到空白
        else if (s[current_char] == ' ')
        {
            //--- 繼續檢查，直到不是空白
            while (s[current_char + shift_index] == ' ')
            {
                shift_index += 1;
            }
            current_char = current_char + shift_index;
            word_num += 1;
            shift_index = 1;
        }
        else
        {
            consonants_num += 1;
            current_char += 1;
        }
    }
    if (s[current_char - 1] != ' ')
        word_num += 1;
    cout << "vowels_num = " << vowels_num << endl;
    cout << "consonants_num = " << consonants_num << endl;
    cout << "word_num = " << word_num << endl;
    return 0;
}
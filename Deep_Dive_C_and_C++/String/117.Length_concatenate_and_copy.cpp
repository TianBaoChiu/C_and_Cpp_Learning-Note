#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    //--- strlen
    //--- 讀取字串長度
    char s[50] = "Hello";
    char s1[50] = "Paul Chiu";

    cout << strlen(s) << endl;

    cout << strlen(s1) << endl;

    //--- strcat
    //--- 連接兩個string
    char s11[20] = "Good";    // G o o d \0
    char s22[20] = "Morning"; // M o r n i n g \0
    char s33[5] = "Paul";

    // 原本s11中null character的部分被換成M
    strcat(s11, s22);
    cout << s11 << endl;

    // 可以指定要連接的字元數量
    strncat(s11, s33, 3);
    cout << s11 << endl;

    //--- strcpy
    //--- 複製字串
    char s111[20] = "Good";
    char s222[20] = "";

    strcpy(s222, s111);

    cout << s222 << endl;

    //--- strstr
    //--- 在字串中尋找字串
    char s_main[20] = "Programming";
    char s_sub[20] = "gram";

    // strstr會循找目標字串並回傳該目標字串後直到null character的所有字元
    // 沒找到時會回傳null，但cout不可以打印null，所以可以把該動作當成判別是
    // 不等於null時才去執行cout的動作
    cout << strstr(s_main, s_sub) << endl;

    //--- strtol strtof
    char s_int[20] = "3258952";
    char s_float[30] = "32.5985";

    long int x = strtol(s_int, NULL, 10); // 10代表10進制
    float y = strtof(s_float, NULL);

    cout << x << endl
         << y << endl;

    //--- strtok
    char s_tok[20] = "x=10;y=20;z=35";
    char *token = strtok(s_tok, "=;");

    while (token != NULL)
    {
        /* code */
        cout << token << endl;
        //--- 這邊較為關鍵
        //--- 在使用 strtok 函數時, 第一次呼叫時需要傳入要切割的字串和分隔符號(delimiter)。
        //--- 接下來如果要繼續切割同一個字串的剩餘部分,就需要將第一個參數設為 NULL。
        //--- 這告訴 strtok 函數繼續在先前傳入的字串上進行切割動作,而第二個參數則重新指定分隔符號。
        //--- strtok 函數在切割字串時會記錄上一次切割的位置,所以在下一次呼叫時不需要重新傳入完整字串,
        //--- 只需要告知分隔符號即可。如果第一個參數不是 NULL,它會從頭開始重新切割傳入的新字串。
        token = strtok(NULL, "=;");
    }

    return 0;
}
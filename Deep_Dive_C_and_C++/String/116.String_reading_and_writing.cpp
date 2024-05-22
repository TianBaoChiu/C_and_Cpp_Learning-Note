#include <iostream>
using namespace std;

int main()
{
    char A[20];
    char A2[20];

    cout << "1" << endl;

    // 注意cin.get遇到會讀取到換行符之前，所以不會包含換行符號
    cin.get(A, 20);

    cout << A << endl;

    // 透過ignore可以忽略原本輸入的\n，或是使用cin.getline()來抓取包含換行符的輸入
    cin.ignore();

    cout << "2" << endl;
    cin.get(A2, 20);
    cout << A2 << endl;

    return 0;
}
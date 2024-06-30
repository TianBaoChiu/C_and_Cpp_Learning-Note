#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int Validation_function(char *name)
{
    int i;
    for (i = 0; name[i] != '\0'; i++)
    {
        if (!(name[i] >= 65 && name[i] <= 90) &&
            !(name[i] >= 97 && name[i] <= 122) &&
            !(name[i] >= 48 && name[i] <= 57))
        {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    char name[] = "Admin1234";
    int validation;

    validation = Validation_function(name); //--- name 數組會自動退化（decay）為指向其第一個元素的指針
    printf("%d\n", validation);

    return 0;
}
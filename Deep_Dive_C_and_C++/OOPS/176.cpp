#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Student
{
public:
    int roll_num;
    string name;
    int math;
    int phy;
    int chem;
    int total;

    Student()
    {
        roll_num = 5;
        name = "David";
        math = 60;
        phy = 30;
        chem = 90;
    }

    void total_function()
    {
        total = math + phy + chem;
    }

    char grade()
    {
        float average = total / 3;

        if (average > 60)
            return 'A';
        else if (average >= 40 && average < 60)
            return 'B';
        else
            return 'C';
    }
};

int main(void)
{
    Student r1;

    printf("grade is %c\n", r1.grade());

    return 0;
}
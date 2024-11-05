#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Stack
{
private:
    int size;
    int top;
    char *s;

public:
    Stack(int size)
    {
        top = -1;
        s = new char[size];
    };
    void push(char x);
    int pop();
    int isempty();
};

void Stack::push(char x)
{
    if (top == size - 1)
    {
        printf("Stack is overflow\n");
        return;
    }
    top++;
    s[top] = x;
}
int Stack::pop()
{
    char x;
    if (top == -1)
    {
        printf("Stack is underflow\n");
        return -1;
    }
    x = s[top];
    top--;
    return 0;
}
int Stack::isempty()
{
    return top == -1 ? 1 : 0;
}

int main(void)
{
    string str = "((a + b) * (c + d)";
    int size = str.size();

    Stack stk(size);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
        {
            stk.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (stk.isempty())
            {
                printf("Stack is empty\n");
                printf("Not balance\n");
                return 0;
            }
            stk.pop();
        }
    }
    if (stk.isempty())
        printf("Is balance\n");
    else
        printf("Is not balance\n");
    return 0;
}
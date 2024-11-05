#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack() { top = NULL; }
    void push(int value);
    int pop();
    void Display();
};

void Stack::push(int value)
{
    Node *t = new Node();
    if (t == NULL)
        cout << "Stack is full" << endl;
    else
    {
        t->data = value;
        t->next = top;
        top = t;
    }
}
int Stack::pop()
{
    Node *t = new Node();
    int value = -1;
    if (top == NULL)
        cout << "Stack is empty" << endl;
    else
    {
        value = top->data;
        t = top;
        top = top->next;
        delete t;
    }

    return value;
}
void Stack::Display()
{
    Node *p = top;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main(void)
{

    Stack stk;

    stk.push(10);
    stk.push(20);
    stk.push(30);

    stk.Display();

    cout << "pop value" << stk.pop() << endl;
    stk.Display();

    return 0;
}
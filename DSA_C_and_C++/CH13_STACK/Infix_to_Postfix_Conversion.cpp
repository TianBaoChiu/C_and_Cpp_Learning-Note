#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

class Stack
{
private:
    std::vector<char> data;
    size_t capacity;

public:
    Stack(size_t size) : capacity(size) {}

    void push(char value)
    {
        if (isFull())
        {
            throw std::runtime_error("Stack Overflow");
        }
        data.push_back(value);
    }

    char pop()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Stack Underflow");
        }
        char value = data.back();
        data.pop_back();
        return value;
    }

    bool isEmpty() const
    {
        return data.empty();
    }

    bool isFull() const
    {
        return data.size() == capacity;
    }

    char top() const
    {
        if (isEmpty())
        {
            throw std::runtime_error("Stack is empty");
        }
        return data.back();
    }
};

bool isOperand(char x)
{
    return (x != '+' && x != '-' && x != '*' && x != '/');
}

int precedence(char x)
{
    switch (x)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

std::string infixToPostfix(const std::string &exp)
{
    Stack stk(exp.size());
    std::string postfix;

    for (char c : exp)
    {
        if (isOperand(c))
        {
            postfix += c;
        }
        else
        {
            while (!stk.isEmpty() && precedence(c) <= precedence(stk.top()))
            {
                postfix += stk.pop();
            }
            stk.push(c);
        }
    }

    while (!stk.isEmpty())
    {
        postfix += stk.pop();
    }

    return postfix;
}

int main()
{
    std::string exp = "a+b*c";
    try
    {
        std::string postfix = infixToPostfix(exp);
        std::cout << "Infix: " << exp << std::endl;
        std::cout << "Postfix: " << postfix << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
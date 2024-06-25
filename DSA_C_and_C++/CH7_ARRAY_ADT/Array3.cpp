#include <iostream>
#include <string>
#include <cstring>

class Array
{
private:
    int *A;
    int size;
    int length;

public:
    Array();
    Array(int sz);
    ~Array();
    void Display();
    void Append(int x);
};

Array::Array()
{
    size = 10;
    length = 0;
    A = new int[10];
}
Array::Array(int sz)
{
    size = sz;
    length = 0;
    A = new int[size];
}

Array::~Array()
{
    delete[] A;
}

void Array::Display()
{
    std::cout << "\nThe array is \n";
    for (int i = 0; i < length; i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
}

void Array::Append(int x)
{
    if (length < size)
    {
        A[length] = x;
        length++;
    }
}

int main(void)
{

    Array arr1(10);

    arr1.Append(2);
    arr1.Append(3);
    arr1.Append(4);
    arr1.Append(5);
    arr1.Append(6);

    arr1.Display();

    return 0;
}
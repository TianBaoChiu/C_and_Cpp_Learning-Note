/*
c++的class方式建立一個對角矩陣
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Diagonal
{
private:
    int n;
    int *A;

public:
    Diagonal(int n);
    ~Diagonal();

    void set(int i, int j, int value);
    void Display();

    int get(int i, int j);
};

Diagonal::Diagonal(int n)
{
    this->n = n;
    A = new int[n];
}
Diagonal::~Diagonal()
{
    delete[] A;
}
void Diagonal::set(int i, int j, int value)
{
    if (i == j)
        A[i - 1] = value;
}
void Diagonal::Display()
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
                printf("%d ", A[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int Diagonal::get(int i, int j)
{
    if (i == j)
        return A[i - 1];
    else
        return 0;
}

int main(void)
{
    Diagonal A(5);
    A.set(1, 1, 5);
    A.set(2, 2, 25);
    A.set(3, 3, 39);
    A.set(4, 4, 5);
    A.set(5, 5, 30);

    A.Display();

    A.~Diagonal();

    return 0;
}
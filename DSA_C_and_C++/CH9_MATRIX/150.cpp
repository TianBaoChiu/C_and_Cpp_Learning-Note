/*Lower Triangular Matrix in C++*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Matrix
{
private:
    /* data */
    int *A;
    int n;

public:
    Matrix();
    Matrix(int n);
    ~Matrix();

    void set(int i, int j, int value);
    void Display();

    int get(int i, int j);
    int getDim();
};

Matrix::Matrix()
{
    n = 3;
    A = new int[3 * (3 + 1) / 2];
}

Matrix::Matrix(int n)
{
    this->n = n;
    A = new int(n * (n + 1) / 2);
}

Matrix::~Matrix()
{
    delete[] A;
}

void Matrix::set(int i, int j, int value)
{
    if (i >= j)
        A[i * (i - 1) / 2 + j - 1] = value; //--- row major
}

void Matrix::Display()
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i >= j)
                printf("%d ", A[i * (i - 1) / 2 + j - 1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int Matrix::get(int i, int j)
{
    if (i >= j)
        return A[i * (i - 1) / 2 + j - 1];
    else
        return 0;
}

int Matrix::getDim()
{
    return n;
}

int main(void)
{
    int n;
    cout << "Enter Dimenstions" << endl;
    cin >> n;
    int x;
    Matrix lm(5);
    cout << "Enter all elements" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            lm.set(i, j, x);
        }
    }
    lm.Display();
    return 0;
}
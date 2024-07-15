#include <stdio.h>

struct Matrix
{
    int A[10];
    int n;
};

void set(struct Matrix *m, int i, int j, int value)
{
    if (i == j)
        m->A[i - 1] = value;
}

int get(struct Matrix m, int i, int j)
{
    if (i == j)
        return m.A[i - 1];
    else
        return 0;
}

void Display(struct Matrix m)
{
    int i, j;
    for (i = 0; i < m.n; i++)
    {
        for (j = 0; j < m.n; j++)
        {
            if (i == j)
                printf("%d ", m.A[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    m.n = 5; //--- 5*5 matrix

    set(&m, 1, 1, 5);
    set(&m, 2, 2, 3);
    set(&m, 3, 3, 10);
    set(&m, 4, 4, 25);
    set(&m, 5, 5, 23);

    Display(m);

    return 0;
}
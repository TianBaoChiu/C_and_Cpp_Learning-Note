/*Lower Triangular Matrix in C*/
#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n;
};

void Set(struct Matrix *m, int i, int j, int value)
{
    if (i >= j)
        m->A[i * (i - 1) / 2 + j - 1] = value; //--- row major
}

int get(struct Matrix m, int i, int j)
{
    if (i >= j)
        return m.A[i * (i - 1) / 2 + j - 1]; //--- row major
    else
        return 0;
}

void Display(struct Matrix m)
{
    int i, j;
    for (i = 0; i <= m.n; i++)
    {
        for (j = 0; j <= m.n; j++)
        {
            if (i >= j)
                printf("%d ", m.A[i * (i - 1) / 2 + j - 1]); //--- row major
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{

    struct Matrix m;
    m.n = 5;
    int i, j;
    int x;
    m.A = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));

    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            scanf("%d", &x);
            Set(&m, i, j, x);
        }
    }

    Display(m);

    return 0;
}
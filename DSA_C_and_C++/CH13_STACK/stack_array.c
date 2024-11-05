#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int Top;
    int *S;
};

void create(struct stack *st, int size)
{
    st->size = size;
    st->Top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}

void Display(struct stack st)
{
    for (int i = st.Top; i >= 0; i--)
        printf("%d ", st.S[i]);
    printf("\n");
}

void Push(struct stack *st, int value)
{
    if (st->Top == st->size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        st->Top++;
        st->S[st->Top] = value;
    }
}

int pop(struct stack *st)
{
    int value = -1;
    if (st->Top == -1)
        printf("Stack Underflow\n");
    else
    {
        value = st->S[st->Top];
        st->Top--;
    }

    return value;
}

int Peek(struct stack st, int index)
{
    int value;
    if (st.Top - index < 0)
        printf("Invalid Index \n");
    else
        value = st.S[st.Top - index + 1];

    return value;
}

int isEmpty(struct stack st)
{
    if (st.Top == -1)
        return 0;
    return 1;
}

int isFull(struct stack st)
{
    return st.Top == st.size - 1;
}

int stackTop(struct stack st)
{
    if (!isEmpty(st))
        return st.S[st.Top];
    return -1;
}

int main()
{
    struct stack st;
    create(&st, 10);

    Push(&st, 10);
    Push(&st, 20);
    Push(&st, 30);
    Push(&st, 40);
    Push(&st, 50);
    Display(st);
    printf("Peek %d\n", Peek(st, 2));

    printf("%d \n", pop(&st));

    return 0;
}

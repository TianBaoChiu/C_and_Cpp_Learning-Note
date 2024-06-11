#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("\nThe array is \n");
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length] = x;
        arr->length++;
    }
}

void Insert(struct Array *arr, int index, int x)
{
    if (index > 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int main(void)
{
    // 初始化一個array
    struct Array arr = {
        {2, 3, 4, 5, 6}, // A[20]
        10,              // size
        5};              // length

    Append(&arr, 10);
    Display(arr);

    Insert(&arr, 3, 33);
    Display(arr);
    return 0;
}
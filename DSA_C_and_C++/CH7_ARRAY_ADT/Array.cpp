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

int Delete(struct Array *arr, int index)
{
    int x = 0;
    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return 0;
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int LinearSearch(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] == key)
            return i;
    }
    return -1;
}

int BinarySearch(struct Array *arr, int key)
{
    int l = 0;
    int h = arr->length - 1; //--- ex : length = 7 index = 6
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr->A[mid] == key)
            return mid;
        else if (arr->A[mid] > key)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int RBinarySearch(struct Array *arr, int key, int l, int h)
{
    if (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr->A[mid] == key)
            return mid;
        else if (arr->A[mid] > key)
            return RBinarySearch(arr, key, l, mid - 1);
        else
            return RBinarySearch(arr, key, l + 1, h);
    }

    return -1;
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

    Delete(&arr, 3);
    Display(arr);

    int key_index = LinearSearch(&arr, 4);
    printf("The index is %d\n", key_index);

    int key_index1 = BinarySearch(&arr, 99);
    printf("The index1 is %d\n", key_index1);

    int key_index2 = RBinarySearch(&arr, 5, 0, arr.length - 1);
    printf("The index2 is %d\n", key_index2);

    return 0;
}
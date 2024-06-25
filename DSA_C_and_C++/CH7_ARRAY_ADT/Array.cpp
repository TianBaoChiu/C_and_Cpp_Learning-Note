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

int Get_function(struct Array *arr, int index)
{
    if (index >= 0 && index < arr->length)
        return arr->A[index];
}

int Max_function(struct Array *arr)
{
    int max = arr->A[0];
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] > max)
            max = arr->A[i];
    }
    return max;
}

int Min_function(struct Array *arr)
{
    int min = arr->A[0];
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->A[i] < min)
            min = arr->A[i];
    }
    return min;
}

int Sum_function(struct Array *arr)
{
    int total = 0;
    for (int i = 0; i < arr->length; i++)
    {
        total += arr->A[i];
    }
    return total;
}

int Avg_function(struct Array *arr)
{
    int total = 0;
    for (int i = 0; i < arr->length; i++)
    {
        total += arr->A[i];
    }

    return total / arr->length;
}

void Reverse_function(struct Array *arr)
{
    int *B;
    int i, j;
    B = new int[arr->length];
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = arr->A[i];
    }
    for (i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }

    delete[] B;
}

void Reverse_function_two(struct Array *arr)
{
    int temp;
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

void Insert_Sorted_Array(struct Array *arr, int x)
{
    int i = arr->length - 1;
    if (arr->length == arr->size)
        return;
    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }

    arr->A[i] = x;
    arr->length += 1;
}

int Array_sorted(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
            return 0;
    }
    return 1;
}

struct Array *Merge(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }

    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    for (; j < arr1->length; j++)
        arr3->A[k++] = arr1->A[j];

    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;
}

struct Array *Union(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }

    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    for (; j < arr1->length; j++)
        arr3->A[k++] = arr1->A[j];

    arr3->length = k;
    arr3->size = 10;

    return arr3;
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

    int get_value = Get_function(&arr, 3);
    printf("Get value is %d\n", get_value);

    int max_value = Max_function(&arr);
    printf("Max value is %d\n", max_value);

    int sum_value = Sum_function(&arr);
    printf("Sum value is %d\n", sum_value);

    int avg_value = Avg_function(&arr);
    printf("Avg value is %d\n", avg_value);

    Reverse_function(&arr);
    Display(arr);

    Reverse_function_two(&arr);
    Display(arr);

    Insert_Sorted_Array(&arr, 6);
    Display(arr);

    int sorted = Array_sorted(arr);
    printf("sorted = %d\n", sorted);

    struct Array arr1
    {
        {2, 6, 10, 15, 25},
            10,
            5
    };
    struct Array arr2
    {
        {3, 4, 7, 18, 20},
            10,
            5
    };
    struct Array *arr3;
    arr3 = Merge(&arr1, &arr2);
    Display(*arr3);

    struct Array arr4
    {
        {2, 6, 10, 15, 25},
            10,
            5
    };
    struct Array arr5
    {
        {3, 6, 7, 15, 20},
            10,
            5
    };
    struct Array *arr6;
    arr6 = Union(&arr4, &arr5);
    Display(*arr6);
    return 0;
}
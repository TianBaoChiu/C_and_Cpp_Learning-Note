#include <iostream>

class Array
{
private:
    int *A;
    int size;
    int length;

    void swap(int *x, int *y);

public:
    Array();
    Array(int sz);
    ~Array();

    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int Delete(int index);
    int LinearSearch(int key);
    int BinarySearch(int key);
    int Get(int index);
    int Max();
    int Min();
    int Sum();
    float Avg();
    void Reverse();
    void InsertSorted(int x);
    bool IsSorted();
    Array *Merge(Array *arr2);
    Array *Union(Array *arr2);
};

Array::Array()
{
    size = 10;
    length = 0;
    A = new int[size];
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

void Array::Insert(int index, int x)
{
    if (index >= 0 && index <= length)
    {
        for (int i = length; i > index; i--)
        {
            A[i] = A[i - 1];
        }
        A[index] = x;
        length++;
    }
}

int Array::Delete(int index)
{
    int x = 0;
    if (index >= 0 && index < length)
    {
        x = A[index];
        for (int i = index; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
        return x;
    }
    return 0;
}

void Array::swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Array::LinearSearch(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (A[i] == key)
            return i;
    }
    return -1;
}

int Array::BinarySearch(int key)
{
    int l = 0;
    int h = length - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (A[mid] == key)
            return mid;
        else if (A[mid] > key)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int Array::Get(int index)
{
    if (index >= 0 && index < length)
        return A[index];
    return -1;
}

int Array::Max()
{
    int max = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

int Array::Min()
{
    int min = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] < min)
            min = A[i];
    }
    return min;
}

int Array::Sum()
{
    int total = 0;
    for (int i = 0; i < length; i++)
    {
        total += A[i];
    }
    return total;
}

float Array::Avg()
{
    return static_cast<float>(Sum()) / length;
}

void Array::Reverse()
{
    for (int i = 0, j = length - 1; i < j; i++, j--)
    {
        swap(&A[i], &A[j]);
    }
}

void Array::InsertSorted(int x)
{
    if (length == size)
        return;

    int i = length - 1;
    while (i >= 0 && A[i] > x)
    {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    length++;
}

bool Array::IsSorted()
{
    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] > A[i + 1])
            return false;
    }
    return true;
}

Array *Array::Merge(Array *arr2)
{
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array(length + arr2->length);

    while (i < length && j < arr2->length)
    {
        if (A[i] < arr2->A[j])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }

    for (; i < length; i++)
        arr3->A[k++] = A[i];

    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;
    return arr3;
}

Array *Array::Union(Array *arr2)
{
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array(length + arr2->length);

    while (i < length && j < arr2->length)
    {
        if (A[i] < arr2->A[j])
            arr3->A[k++] = A[i++];
        else if (arr2->A[j] < A[i])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }

    for (; i < length; i++)
        arr3->A[k++] = A[i];

    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;
    return arr3;
}

int main()
{
    Array arr1(10);
    arr1.Append(2);
    arr1.Append(3);
    arr1.Append(4);
    arr1.Append(5);
    arr1.Append(6);

    arr1.Display();

    arr1.Insert(3, 33);
    arr1.Display();

    arr1.Delete(3);
    arr1.Display();

    std::cout << "Linear Search (4): " << arr1.LinearSearch(4) << std::endl;
    std::cout << "Binary Search (5): " << arr1.BinarySearch(5) << std::endl;

    std::cout << "Get(3): " << arr1.Get(3) << std::endl;
    std::cout << "Max: " << arr1.Max() << std::endl;
    std::cout << "Sum: " << arr1.Sum() << std::endl;
    std::cout << "Avg: " << arr1.Avg() << std::endl;

    arr1.Reverse();
    arr1.Display();

    arr1.InsertSorted(6);
    arr1.Display();

    std::cout << "Is Sorted: " << (arr1.IsSorted() ? "Yes" : "No") << std::endl;

    Array arr2(10);
    arr2.Append(3);
    arr2.Append(4);
    arr2.Append(7);
    arr2.Append(18);
    arr2.Append(20);

    Array *arr3 = arr1.Merge(&arr2);
    arr3->Display();
    delete arr3;

    Array *arr4 = arr1.Union(&arr2);
    arr4->Display();
    delete arr4;

    return 0;
}
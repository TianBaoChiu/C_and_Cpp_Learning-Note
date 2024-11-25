#include <iostream>
using namespace std;

class QueueUsingArray
{
private:
    int MAX_SIZE;
    int front;
    int rear;
    int *arr;
    int count;

public:
    QueueUsingArray(int size = 10) : MAX_SIZE(size), front(0), rear(-1), count(0)
    {
        arr = new int[MAX_SIZE];
    }

    ~QueueUsingArray()
    {
        delete[] arr;
    }

    bool isEmpty() const
    {
        return count == 0;
    }

    bool isFull() const
    {
        return count == MAX_SIZE;
    }

    int peak() const
    {
        if (isEmpty())
        {
            cout << "This queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    void enqueue(int element)
    {
        if (isFull())
        {
            cout << "This queue is full" << endl;
            return;
        }

        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = element;
        count++;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "This queue is empty" << endl;
            throw runtime_error("Empty!");
        }

        int value;
        value = arr[front];
        front = (front + 1) % MAX_SIZE;
        count--;

        return value;
    }

    void Display() const
    {
        if (isEmpty())
        {
            cout << "This queue is empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++)
        {
            cout << "Data is: " << arr[i] << endl;
        }
    }
};

int main()
{
    QueueUsingArray Q;

    Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);
    Q.enqueue(40);
    Q.enqueue(50);

    Q.Display();

    Q.dequeue();

    Q.Display();
    cout << "PEAK" << Q.peak() << endl;
    return 0;
}
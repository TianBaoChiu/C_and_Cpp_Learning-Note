#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    //--- Node 類構造函數，包含成員初始化列表（member initializer list）。它在構造函數體執行之前初始化類的成員。
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
private:
    Node *first;

public:
    //--- 創建時是一個空的指標，代表目前的鏈表中沒有任何節點
    LinkedList() : first(nullptr) {}
    ~LinkedList();
    void create(const vector<int> &A);
    void Display();
    void Insert(int index, int x);
    int Delete(int index);
    int Length();
};

void LinkedList::create(const vector<int> &A)
{
    if (A.empty())
        return;

    first = new Node(A[0]);
    Node *last_node = first;

    for (int i = 1; i < A.size(); i++)
    {
        Node *temp = new Node(A[i]);
        last_node->next = temp;
        last_node = temp;
    }
}
void LinkedList::Display()
{
    Node *p = first;
    while (p != nullptr)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

LinkedList::~LinkedList()
{
    Node *p = first;
    while (p)
    {
        Node *temp = p;
        p = p->next;
        delete temp;
    }
}

int LinkedList::Length()
{
    Node *p = first;
    int count = 0;
    while (p)
    {
        p = p->next;
        count++;
    }

    return count;
}

void LinkedList::Insert(int index, int x)
{
    Node *temp_node = new Node(x);
    Node *p = first;

    if (index < 0 && index > Length())
        return;

    if (index == 0)
    {
        temp_node->next = first;
        first = temp_node;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        temp_node->next = p->next;
        p->next = temp_node;
    }
}

int LinkedList::Delete(int index)
{
    Node *q = nullptr;
    Node *p = first;
    int delete_value = 0;

    if (index < 0 && index > Length())
        return -1;
    for (int i = 0; i < index - 1; i++)
    {
        q = p;
        p = p->next;
    }
    delete_value = p->data;
    q->next = p->next;
    delete p;

    return delete_value;
}

int main(void)
{
    LinkedList list;
    vector<int> arr = {1, 2, 3, 4, 5};
    list.create(arr);

    list.Display();
    int length = list.Length();
    cout << "Length is " << length << endl;

    int delete_value = list.Delete(3);
    cout << "Delete" << delete_value << endl;
    list.Display();
    return 0;
}
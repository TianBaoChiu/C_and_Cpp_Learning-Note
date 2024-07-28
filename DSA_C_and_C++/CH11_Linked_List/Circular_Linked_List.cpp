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

    Node(int value)
    {
        data = value;
        next = nullptr;
    };
};

class LinkedList
{
private:
    Node *Head;

public:
    LinkedList() { Head = nullptr; };
    ~LinkedList();
    void Create(const vector<int> &A, int n);
    void Display();
    void RDisplay(Node *current = nullptr);
    void Insert(int index, int x);
    int Length();
    int Delete(int index);
};

LinkedList::~LinkedList()
{
    if (!Head)
        return;
    Node *current = Head->next;
    while (current != Head)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    delete Head;
}
void LinkedList::Create(const vector<int> &A, int n)
{

    if (A.empty())
        return;
    //--- 循環列表的第一個節點
    Head = new Node(A[0]);
    Node *last_node = Head;
    // //--- 需要指向自己，因為是循環列表
    Head->next = Head;
    last_node = Head;

    Node *t = nullptr;
    for (int i = 1; i < n; i++)
    {
        t = new Node(A[i]);
        t->next = last_node->next;
        last_node->next = t;
        last_node = t;
    }
}
void LinkedList::Display()
{
    Node *current = Head->next;
    cout << Head->data << endl;
    while (current != Head)
    {
        cout << current->data << endl;
        current = current->next;
    }
}

void LinkedList::RDisplay(Node *current)
{
    if (current == nullptr)
    {
        if (Head == nullptr)
        {
            cout << "Head is null" << endl;
            return;
        }
        cout << Head->data << endl;
        if (Head->next != Head)
        {
            RDisplay(Head->next);
        }
        return;
    }

    //--- 遞迴
    if (current != Head)
    {
        cout << current->data << endl;
        RDisplay(current->next);
    }
}

void LinkedList::Insert(int index, int x)
{
    Node *temp = new Node(x);
    temp->next = nullptr;

    if (index == 0)
    {
        if (!Head)
        {
            Head = temp;
            Head->next = Head;
        }
        else
        {
            temp->next = Head;
            Node *p = Head;
            while (p->next != Head)
            {
                p = p->next;
            }
            p->next = temp;
            Head = temp;
        }
    }
    else
    {
        Node *p = Head;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
}

int LinkedList::Length()
{
    int count = 1;
    Node *p = Head;
    do
    {
        count++;
        p = p->next;
        /* code */
    } while (p->next != Head);

    return count;
}

int LinkedList::Delete(int index)
{
    int delete_value;

    if (index < 0 || index > Length())
        return -1;

    if (index == 1)
    {
        Node *p = Head;
        while (p->next != Head)
        {
            p = p->next;
        }
        delete_value = Head->data;
        //--- 檢查這個鏈表是不是只有一個節點
        if (p == Head)
        {
            delete Head;
            Head = nullptr;
        }
        else
        {
            p->next = Head->next;
            delete Head;
            Head = p->next;
        }
    }
    else
    {
        Node *p = Head;
        Node *q = nullptr;

        for (int i = 0; i < index - 2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        delete_value = q->data;

        delete q;
        q = nullptr;
    }
    return delete_value;
}

int main(void)
{
    LinkedList list;
    vector<int> A = {1, 2, 3, 4, 5};

    list.Create(A, 5);
    // list.Display();

    list.Insert(0, 5);
    list.Insert(3, 88);
    list.Display();

    int total_length = list.Length();
    cout << "length" << total_length << endl;

    int delete_value = list.Delete(6);
    cout << "delete value is " << delete_value << endl;
    list.Display();

    cout << "program end" << endl;
    return 0;
}
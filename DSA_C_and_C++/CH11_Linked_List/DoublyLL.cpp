#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class Node
{
public:
    Node *pre;
    int data;
    Node *next;

    Node(int value)
    {
        pre = nullptr;
        data = value;
        next = nullptr;
    };
};

class LinkedList
{
private:
    Node *first;

public:
    LinkedList() { first = nullptr; };
    ~LinkedList();
    void Create(vector<int> A, int n);
    void Display();
    int Length();
};

LinkedList::~LinkedList()
{
    if (!first)
        return;
    Node *current_node = first;
    while (current_node)
    {
        Node *temp = current_node;
        current_node = current_node->next;
        delete temp;
    }
}
void LinkedList::Create(vector<int> A, int n)
{
    if (n == 0) //--- if vector is empty, do nothing
        return;
    first = new Node(A[0]);
    Node *last_node = first;

    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(A[i]);
        last_node->next = temp;
        temp->pre = last_node;
        last_node = temp;
    }
}

void LinkedList::Display()
{
    Node *current_node = first;
    while (current_node)
    {
        cout << current_node->data << endl;
        current_node = current_node->next;
    }
}

int LinkedList::Length()
{
    int count = 0;
    Node *current_node = first;
    while (current_node)
    {
        current_node = current_node->next;
        count++;
    }

    return count;
}

int main(void)
{
    LinkedList Doubly_list;
    vector<int> A = {1, 2, 3, 4, 5};
    Doubly_list.Create(A, 5);
    Doubly_list.Display();

    int count = Doubly_list.Length();
    cout << "Length is " << count << endl;

    return 0;
}
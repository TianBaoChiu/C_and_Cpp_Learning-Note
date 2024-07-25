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

int main(void)
{
    LinkedList list;
    vector<int> arr = {1, 2, 3, 4, 5};
    list.create(arr);

    list.Display();

    return 0;
}
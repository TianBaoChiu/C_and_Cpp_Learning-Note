/*
Content about Linked List
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void create(int A[], int n)
{
    struct Node *t;         //---建立一個暫時的節點
    struct Node *last_node; //---紀錄整個鏈表的結尾
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last_node = first;

    for (int i = 1; i < n; i++)
    {
        //--- 建立一個新節點
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;

        //--- 將當前的最後一個節點與新節點連接。
        last_node->next = t;

        //--- 這一行確保 last_node 始終指向鏈表的最後一個節點，使得下一次迭代可以正確地將新節點添加到鏈表的末尾。
        last_node = t;
    }
}
void create2(int A[], int n)
{
    struct Node *t;         //---建立一個暫時的節點
    struct Node *last_node; //---紀錄整個鏈表的結尾
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last_node = second;

    for (int i = 1; i < n; i++)
    {
        //--- 建立一個新節點
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;

        //--- 將當前的最後一個節點與新節點連接。
        last_node->next = t;

        //--- 這一行確保 last_node 始終指向鏈表的最後一個節點，使得下一次迭代可以正確地將新節點添加到鏈表的末尾。
        last_node = t;
    }
}

//--- 顯示每個元素，使用迭代法
void Display(struct Node *p)
{

    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

//--- 顯示每個元素，使用遞迴
void RDisplay(struct Node *p)
{

    if (p != NULL)
    {
        printf("data = %d\n", p->data);
        RDisplay(p->next);
    }
}

//--- 計算鏈表的數量，使用迭代
int Count(struct Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

//--- 計算鏈表的數量，使用遞迴
int RCount(struct Node *p)
{
    if (p != NULL)
        return RCount(p->next) + 1; //--- 這邊很重要 一定要把+1放在後面，否則會使1加上一個未定義的內容
    else
        return 0;
}

//--- 計算鏈表的總和，使用迭代
int Sum(struct Node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }

    return sum;
}

//--- 計算鏈表的總和，使用遞迴
int RSum(struct Node *p)
{
    if (p != NULL)
        return RSum(p->next) + p->data;
    else
        return 0;
}

int Max(struct Node *p)
{
    int max = 0;
    while (p != NULL)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }

    return max;
}

int RMax(struct Node *p)
{
    int x = 0;
    if (p == 0)
        return 0;
    x = RMax(p->next);
    if (x > p->data)
        return x;
    else
        return p->data;
}

struct Node *L_Search(int key, struct Node *p)
{
    while (p != NULL)
    {
        if (p->data == key)
            return p;
        p = p->next;
    }
}
struct Node *RL_Search(int key, struct Node *p)
{
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;
    return RL_Search(key, p->next);
}

struct Node *L_Search_Move_to_head(int key, struct Node *p)
{
    struct Node *q;

    while (p != NULL)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
}

void Insert_node(int pos, int x, struct Node *p)
{
    struct Node *t;

    if (pos < 0 || pos > Count(p))
        return;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (pos == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}
void SortedInsert(struct Node *p, int x)
{
    struct Node *q;
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (first == NULL)
        first = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

void DeleteNode(struct Node *p, int pos)
{
    if (pos < 1 || pos > Count(p))
        return;

    struct Node *q = NULL;
    if (pos == 1)
    {
        q = first;
        first = first->next;
        free(q);
    }
    else
    {

        for (int i = 0; i < pos - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        free(p);
    }
}

int IsSorted(struct Node *p)
{
    int x = 0;
    while (p)
    {
        if (p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

void Remove_duplicates(struct Node *p)
{
    struct Node *q;
    q = p->next;
    while (q)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

void Reverse1(struct Node *p)
{
    int *A, i = 0;
    struct Node *q; //--- 透過移動q來走完整個鏈表，p就不要動了，避免遺失起始的地址
    q = p;
    A = (int *)malloc(sizeof(int) * Count(p));

    //--- 把鏈表的值儲存到陣列中
    while (q)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }

    //--- 抵達鏈表的結尾，讓鏈表回到起點，然後反著讀取陣列
    q = p;
    i--;
    while (q)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

void Reverse2(struct Node *p)
{
    struct Node *r = NULL;
    struct Node *q = NULL;

    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void Reverse3(struct Node *q, struct Node *p)
{
    if (p)
    {
        Reverse3(p, p->next); //--- 先進度到下一個節點
        p->next = q;          //--- 返回時就反轉節點的指向
    }
    else //--- 節點走到最後了，所以當前q會指在最後節點上
        first = q;
}

void Concat(struct Node *p, struct Node *q)
{

    third = p; //--- 用以紀錄連結後的鏈表
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}

void Merge(struct Node *p, struct Node *q)
{
    //---先決定新鏈表的起點要在哪一個鏈表開始
    struct Node *last_node;
    if (p->data <= q->data)
    {
        third = last_node = p;
        p = p->next;
        last_node->next = NULL;
    }
    else
    {
        third = last_node = q;
        q = q->next;
        last_node->next = NULL;
    }
    //--- merge兩個鏈表
    while (p && q) //--- 確保兩個鏈表都還有節點可以merge
    {
        if (p->data <= q->data)
        {
            last_node->next = p;
            last_node = p;
            p = p->next;
            last_node->next = NULL;
        }
        else
        {
            last_node->next = q;
            last_node = q;
            q = q->next;
            last_node->next = NULL;
        }
    }
    //--- 當某一個鏈表已經沒有節點了，那就把最後節點指向其餘的鏈表
    if (p)
        last_node->next = p;
    if (q)
        last_node->next = q;
}

int main()
{
    int A[] = {1, 20, 30, 40, 50};
    int B[] = {5, 15, 25, 35, 55};
    create(A, 5);
    create2(B, 5);

    Display(first);
    Display(second);

    Merge(first, second);
    Display(third);
    return 0;
}
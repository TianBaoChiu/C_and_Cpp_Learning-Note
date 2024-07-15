/*
Content about Linked List
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

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

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);

    printf("Display elements by iteration method\n");
    Display(first);

    printf("Display elements by recursion method\n");
    RDisplay(first);

    printf("Get linked list length use iteration method\n");
    int count = Count(first);
    printf("Length is %d\n", count);

    printf("Get linked list length use recursion method\n");
    int r_count = RCount(first);
    printf("Length is %d\n", r_count);

    printf("Get sum of a linked list by iteration method\n");
    int sum = Sum(first);
    printf("The sum is %d\n", sum);

    printf("Get sum of a linked list by recursion method\n");
    int r_sum = Sum(first);
    printf("The sum is %d\n", r_sum);

    return 0;
}
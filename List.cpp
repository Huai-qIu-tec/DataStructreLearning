#include <iostream>
using namespace std;


typedef struct LNode
{
    int data;               //每个节点存放的数据
    struct LNode *next;     //每个节点指向下一个节点
}LNode, *LinkList;

bool InitEmptyList(LinkList &L)
{
    L = nullptr;
    return true;
}


bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if(L == nullptr)
        return false;
    L->next = nullptr;
    return true;
}

bool Empty(LinkList L)
{
    return (L == nullptr);
}

// 尾插法
LinkList List_TailInsert(LinkList &L)
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while(x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = nullptr;
    return L;
}

// 不带头结点的尾插法
LinkList List_NoHeadTailInsert(LinkList &L)
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    r->data = x;
    scanf("%d", &x);
    while(x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = nullptr;
    return L;
}

// 头插法
// LinkList List_HeadInsert(LinkList &L)
// {
//     int x;
//     L = (LNode *)malloc(sizeof(LNode));
//     L->next = nullptr;
//     scanf("%d", &x);
//     while(x != 9999)
//     {
//         LNode *s = (LNode *)malloc(sizeof(LNode));
//         s->data = x;
//         s->next = nullptr;
//         L->next = s;
//         scanf("%d", &x);
//     }
//     return L;
// }

void PrintList(LinkList L, int i)
{
    // i == 1时, 表示带头节点
    LNode *p;
    if(i == 1)
        p = L->next;
    else
        p = L;
    while(p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 获得第i个节点
LNode *GetElem(LinkList L, int i)
{
    int j = 1;
    LNode *p = L->next;
    if(i == 0)
        return L;
    if(i < 1)
        return nullptr;
    while (p != nullptr && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

// 链表插入下一个节点
bool InsertNextNode(LNode *p, int e)
{
    if(p == nullptr)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s == nullptr)
        return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 链表插入
bool ListInsert(LinkList &L, int i, int e)
{
    if(i < 1)
        return false;
    LNode *p = GetElem(L, i-1);
    if(InsertNextNode(p, e))
        return true;
    else
        return false;
}


// 链表删除
bool ListDelete(LinkList &L, int i, int &e)
{
    if(i < 1)
        return false;
    LNode *p = GetElem(L, i - 1);
    if(p == nullptr)
        return false;
    if(p->next == nullptr)
        return false;
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

int Length(LinkList L)
{
    LNode *p = L->next;
    int length = 0;
    while(p != nullptr)
    {
        p = p->next;
        length++;
    }
    return length;
}

// 递归删除链表中所以data = e的结点
void DeleteLinkX(LinkList &L, int e)
{
    // 当L为空时出递归
    if(L == nullptr)
        return;
    LNode *p;
    // 当L->data == e时，删除*L, 并指向下一节点
    if(L->data == e)
    {
        p = L;
        L = L->next;
        free(p);
        DeleteLinkX(L, e);
    }
    else
        DeleteLinkX(L->next, e);
}

void PrintLinkReverse(LinkList L)
{
    if(L != nullptr)
    {
        if(L->next != nullptr)
        {
            PrintLinkReverse(L->next);
        }
        cout << L->data << " ";
    }
}


int main(void)
{
    LinkList L;
    List_TailInsert(L);
    PrintList(L, 1);
    PrintLinkReverse(L);
    system("pause");
}
#include <iostream>
using namespace std;

typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
}DNode, *DLinklist;

bool InitDoubleLinklist(DLinklist &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if(L == nullptr)
        return false;
    L->prior = nullptr;
    L->next = nullptr;
    return true;
}

bool empty(DLinklist L)
{
    if(L->next == nullptr)
        return true;
    else
        return false;
}

// 在p结点之后插入s结点
bool InsertNextNode(DNode *p, DNode *s)
{
    if(p == nullptr)
        return false;
    s->next = p->next;
    if(p->next == nullptr)
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

// 删除p的后继结点
bool DeleteNode(DNode *p)
{
    if(p == nullptr)
        return false;
    DNode *q = p->next;
    if(q == nullptr)
        return false;
    p->next = q->next;
    if(q->next != nullptr)
        q->next->prior = p;
    free(q);
    return true;
}

// 销毁链表
void DestoryLinklist(DLinklist &L)
{
    while(L->next != nullptr)
        DeleteNode(L);
    free(L);
    L = nullptr;
}

int main(void)
{

}
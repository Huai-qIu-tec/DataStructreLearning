#include <iostream>
using namespace std;

typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *front, *rear;
}LinkQueue;

void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));  // 建立头节点
    Q.front->next = nullptr;
}

bool Empty(LinkQueue Q)
{
    if(Q.front == Q.rear)
        return true;
    else
        return false;
}

void EnQueue(LinkQueue &Q, int x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = nullptr;
    Q.rear->next = s;
    Q.rear = s;
}

bool DeQueue(LinkQueue &Q, int &x)
{
    if(Q.front == Q.rear)
        return false;
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if(Q.rear==p)
        Q.front = Q.rear;
    free(p);
    return true;
}

int main(void)
{
    LinkQueue Q;
    InitQueue(Q);
    cout << Empty(Q) << endl;
    int e = -1;
    EnQueue(Q, 1);
    cout << Empty(Q) << endl;
    EnQueue(Q, 2);
    DeQueue(Q, e);
    cout << e << endl;
    DeQueue(Q, e);
    cout << e << endl;
    cout << Empty(Q) << endl;
    system("pause");
}
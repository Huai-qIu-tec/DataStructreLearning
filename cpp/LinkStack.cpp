#include <iostream>
using namespace std;

typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}*LiStack, LiNode;


bool Empty(LiStack S)
{
    return (S == nullptr);
}

// 不带头结点的push
void Push(LiStack &S, int e)
{
    LiNode *s;
    if(Empty(S))
    {
        S = (LiStack)malloc(sizeof(LiStack));
        S->next = nullptr;
        S->data = e;
    }
    else
    {
        s = (LiNode *)malloc(sizeof(LiNode));
        s->data = e;
        s->next = S;
        S = s;
    }

}

// 带头节点的push
bool HeadPush(LiStack &S, int e)
{
    LiNode *s;
    if(Empty(S))
    {
        S = (LiStack)malloc(sizeof(LiStack));
        S->next = nullptr;
        s = (LiNode *)malloc(sizeof(LiNode));
        s->data = e;
        s->next = nullptr;
        S->next = s;
    }
    else
    {
        s = (LiNode *)malloc(sizeof(LiNode));
        s->data = e;
        s->next = S->next;
        S->next = s;
    }
    return true;

}

int pop(LiStack &S, int i)
{
    if(i == 1)
    {
        int e = S->data;
        LiNode *p = S;
        S = p->next;
        if(S)
            free(p);
        return e;
    }
    else
    {
        int e = S->next->data;
        LiNode *p = S->next;
        S->next = p->next;
        free(p);
        return e;
    }
}


int main(void)
{
    LiStack S = nullptr;
    for(int i = 0; i < 100; i++)
    {
        Push(S, i);
    }
    for(int i = 0; i < 100; i++)
    {
        int e = pop(S, 1);
        cout << e << endl;
    }
    system("pause");

}
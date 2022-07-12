#include <iostream>
using namespace std;
# define MaxSize 10

typedef struct{
    int data[MaxSize];
    int top;            // 栈顶指针
}SqStack;

void InitStack(SqStack &S)
{
    S.top = -1;
}

bool Empty(SqStack &S)
{
    if(S.top == -1)
        return true;
    else
        return false;
}

bool push(SqStack &S, int e)
{
    if(S.top == MaxSize - 1)
        return false;
    S.data[++S.top] = e;
    return true;
}

bool pop(SqStack &S, int &e)
{
    if(S.top == -1)
        return false;
    e = S.data[S.top--];
    return true;
}

bool GetTop(SqStack &S, int &e)
{
    if(S.top == -1)
        return false;
    e = S.data[S.top];
    return true;
}

int main(void)
{
    SqStack S;
    InitStack(S);
    push(S, 3);
    push(S, 2);
    int e = -1;
    GetTop(S, e);
    cout << e << endl;
    e = -1;
    pop(S, e);
    cout << e << endl;
    e = -1;
    pop(S, e);
    cout << e << endl;
    system("pause");
}
#include <iostream>
#include 

using namespace std;
# define MaxSize 255

typedef struct{
    char ch[MaxSize];
    int length;
}SString;


/*
T = {0, 'a', 'b', 'c', 'd'};
    loop    i   j   next[]
    0       1   0   next[1] = 0
    1       2   1   next[2] = 1
    2       2   0   
    3       3   1   next[3] = 1
    4       3   0   
    5       4   1   next[4] = 1
*/

void get_next(SString T, int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    while(i < T.length)
    {
        if(j == 0 || T.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

int Index_KMP(SString S, SString T, int next[])
{
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length)
    {
        if(j == 0 || S.ch[i] == T.ch[j])
        {   
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    if(j > T.length)
        return i - T.length;
    else
        return 0;
}

int main(void)
{
    char s[9] = {'a', 'b', 'c', 'e', 'a', 'b', 'c', 'd'};
    char t[5] = {'a', 'b', 'c', 'd'};
    SString S;
    SString T;
    for(int i = 0; i < 8; i++)
        S.ch[i+1] = s[i];
    S.length = 9;
    for(int i = 0; i < 4; i++)
        T.ch[i+1] = t[i];
    T.length = 5;
    int next[5] = {0, 0, 0, 0, 0};
    get_next(T, next);
    cout << Index_KMP(S, T, next);
    system("pause");
}
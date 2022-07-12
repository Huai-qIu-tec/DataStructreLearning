#include <iostream>
using namespace std;


int main()
{
    int n;
    scanf("%d", &n);
    int tmp1 = 0;
    int tmp2 = 1;
    int tmp3 = 0;
    for(int i = 2; i <= n ; i++)
    {
        tmp3 = tmp1 + tmp2;
        tmp1 = tmp2;
        tmp2 = tmp3;
    }
    cout << tmp3 << endl;
    system("pause");
}
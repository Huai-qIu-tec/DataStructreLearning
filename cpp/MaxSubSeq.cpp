#include <iostream>
using namespace std;


int main(void)
{
    int p[8] = {-1, 3, -2, 4, -6, 1, 7, -1};
    int N = 8;
    int ThisSum, MaxSum;
    ThisSum = MaxSum = 0;
    for(int i = 0; i < N; i++)
    {
        ThisSum += p[i];
        if(ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if(ThisSum < 0)
            ThisSum = 0;
    }
    cout << MaxSum << endl;
    system("pause");
    return 0;
}

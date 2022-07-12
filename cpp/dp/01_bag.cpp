#include <iostream>
using namespace std;
const int N = 1010;
int V[N], W[N];
//int f[N][N];
int f[N];
int n, w;
int path[N][N];

int main(void)
{
    cin >> n >> w;
    for(int i = 1; i <= n; i++)
    {
        cin >> W[i] >> V[i];
    }
    for(int i = 0; i < N; i++)
        f[i] = -100000000;
    f[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = w; j >= W[i]; j--)
        {
            //f[i][j] = max(f[i][j], f[i-1][j-W[i]] + V[i]);
            if(f[j] < f[j - W[i]] + V[i])
            {
                path[i][j] = 1;
                 f[j] = f[j - W[i]] + V[i];
            }
            if(f[j] < 0)
                f[j] = -100000000;
        }
    }
    /*for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= v; j++)
            cout << f[i][j] << " ";
        cout << endl;
    }*/
    // for(int j = 0; j <= w; j++)
    //     cout << f[j] << " ";
    // cout << endl;
    // cout << f[w] << endl;
    int p = w;
    for(int i = n; i >= 0; i--)//路径输出 
	{
		if(w < 0) break;
		if(path[i][p])
		{
			cout << W[i] << ' ';
			p -= W[i];
		}
    }
    cout << endl;
    if (f[w] > 0)
	{
		cout << f[w] << endl;//背包恰好装满了，输出结果
	}
	else
	{
		cout << "error" << endl;//背包不能恰好装满
	}
    system("pause");
    return 0;
}
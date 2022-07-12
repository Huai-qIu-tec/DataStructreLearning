#include <iostream>
using namespace std;
const int N = 100;
int temp[N];

void Print(int array[], int n)
{
    for(int i = 0; i < n; i++)
        cout << array[i] << "\t";
}


/*
快排的核心
1.确定partition, 划分值

2.确定划分区间

3.递归
*/
void quick_sort(int array[], int l, int r)
{
    if(l >= r)
        return;
    
    int x = array[l], i = l - 1, j = r + 1;
    while(i < j)
    {
        do i++; while(array[i] < x);
        do j--; while(array[j] > x);
        if(i < j)
            swap(array[i], array[j]);
    }
    quick_sort(array, l, j);
    quick_sort(array, j + 1, r);
}


/*
归并排序的核心
1.递归

2.排序

3.合并
*/
void merge_sort(int array[], int l, int r)
{
    if(l >= r)  return;
    int mid = (l + r) / 2;
    merge_sort(array, l, mid);
    merge_sort(array, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r)
    {
        if(array[i] <= array[j]) 
            temp[k++] = array[i++];
        else    
            temp[k++] = array[j++];
    }
    while(i <= mid) temp[k++] = array[i++];
    while(j <= r)   temp[k++] = array[j++];
    for(int i = l, j = 0; i <= r; i++, j++)
        array[i] = temp[j];
}


int main(void)
{
    int array[N];
    srand(N);
    for(int i = 0; i < N; i++)
    {
        array[i] = rand();
        cout << array[i] << "\t";
    }

    //quick_sort(array, 0, N);
    merge_sort(array, 0, N - 1);
    cout << "\n\n";
    Print(array, N);
    system("pause");
    return 0;
}
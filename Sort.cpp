#include <iostream>
#include <time.h>
#include <random>
using namespace std;



typedef struct LNode
{
    int data;               //每个节点存放的数据
    struct LNode *next;     //每个节点指向下一个节点
}LNode, *LinkList;


void InitList(LinkList &L,int array[], int n)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = nullptr;
    LNode *p, *r = L;
    for(int i = 0; i < n; i++)
    {
        p = (LNode *)malloc(sizeof(LNode));
        p->data = array[i];
        r->next = p;
        r = p;
    }
    r->next = nullptr;
}

void Print(int array[], int n)
{
    for(int i = 0; i < n; i++)
        cout << array[i] << "\t";
}

void PrintListArray(LinkList L, int n)
{
    LNode* p = (LNode *)malloc(sizeof(LNode));
    p = L;
    while(p->next != nullptr)
    {
        p = p->next;
        cout << p->data << " ";
    }
}

void InsertSort(int array[], int n)
{
    int i, j, temp;
    for(i = 1; i <= n; i++)
        if(array[i] < array[i-1])
        {
            temp = array[i];
            for(j = i-1; j >=0 && array[j] > temp; j--)
                array[j+1] = array[j];
            array[j+1] = temp;
        }
}

void BinaryInsertSort(int array[], int n)
{
    int i, j, temp, low, high, mid;
    for(i = 1; i <= n; i++)
        if(array[i] < array[i-1])
        {
            low = 0;
            high = i-1;
            int temp = array[i];
            while(low <= high)
            {
                mid = (low + high) / 2;
                if(array[mid] > temp)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            for(j = i - 1; j >= high + 1; j--)
                array[j+1] = array[j];
            array[high + 1] = temp;
        }
}

// 链表插入排序
void ListInsertSort(LinkList &L, int n)
{
    LNode* p = (LinkList)malloc(sizeof(LNode));
    LNode* cur = (LinkList)malloc(sizeof(LNode));
    LNode* pre = (LinkList)malloc(sizeof(LNode));
    p = L;
    pre = p->next;
    
    for(cur = pre->next; cur != nullptr;)
        if(cur->data < pre->data)
        {
            while(p->next->data <= cur->data)
                p = p->next;
            pre->next = cur->next;  // pre指向未被排序的其他node
            cur->next = p->next;    // cur插入比cur的data大的前一个结点
            p->next = cur;          // 将当前链表中比cur的data小的结点链上cur
            p = L;
            cur = pre->next;
        }
}

// LNode* min(LinkList L)
// {
//     LNode*s, *q = (LinkList)malloc(sizeof(LNode));
//     q = L;
//     int temp = q->data;
//     s = q;
//     while(q)
//     {
//         if(temp > q->data)
//         {
//             temp = q->data;
//             s = q;
//         }
//         q = q->next;
//     }
//     return s;
// }

// 链表简单选择排序
void ListSelectSort(LinkList &L, int n)
{
    
    LNode* p, *q, *s = (LinkList)malloc(sizeof(LNode));
    p = q = L->next;
    while(p)
    {
        int temp = p->data;
        s = q;
        while(q)
        {
            if(temp > q->data)
            {
                temp = q->data;
                s = q;
            }
            q = q->next;
        }
        s->data = p->data;
        p->data = temp;
        p = p->next;
        q = p;
    }
}

void ShellSort(int array[], int n)
{
    int temp, i, j, d;
    for(d = n/2; d >= 1; d/=2)
        for(i = d; i < n; i++)
            if(array[i] < array[i-d])
            {
                temp = array[i];
                for(j = i-d; j >= 0 && array[j] > temp; j-=d)
                    array[j+d] = array[j];
                array[j+d] = temp;
            }
}

void BubbleSort(int array[], int n)
{
    bool flag = true;
    int i, j;
    time_t start, end;
    start = clock();
    for(i = 0; i < n - 1; i++)
    {
        flag = false;
        for(j = 0; j < n - 1 - i; j++)
            if(array[j] > array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                flag = true;
            }
    }
    end = clock();
    cout << "time:" << (double)(end - start)/ CLOCKS_PER_SEC << endl;
}

int Partition(int arrar[], int low, int high)
{
    int pivot = arrar[low];
    while(low < high)
    {
        while(low < high && arrar[high] >= pivot)   high--;
        arrar[low] = arrar[high];
        while(low < high && arrar[low] <= pivot)    low++;
        arrar[high] = arrar[low];
    }
    arrar[low] = pivot;
    return low;
}

void QuickSort(int array[], int low, int high)
{
    if(low < high)
    {
        int pivotpos = Partition(array, low, high);
        QuickSort(array, low, pivotpos - 1);
        QuickSort(array, pivotpos + 1, high);
    }
}

void HeadAdjust(int array[], int k, int n)
{
    int i, j, temp;
    i = k;
    j = 2 * i + 1;
    while(j <= n)
    {
        if(j < n && array[j] < array[j+1])    j++;
        if(array[i] > array[j])     break;
        else{
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i = j;
            j = 2 * i + 1;
        }
    }
}

void HeapSort(int array[], int n)
{
    int i, temp;
    for(i = ceil(n/2) - 1; i >=0; i--)
        HeadAdjust(array, i, n-1);
    for(i = 1; i < n; i++)
    {
        temp = array[0];
        array[0] = array[n-i];
        array[n-i] = temp;
        HeadAdjust(array, 0, n - i - 1);
    }
}

void Merge(int array[], int low, int mid, int high, int n)
{
    int *temp = new int[n];
    int i, j, k;
    for(k = low; k <= high; k++)
        temp[k] = array[k];
    for(i = low, j = mid+1, k = i; i<=mid && j<=high;k++)
    {
        if(temp[i] <= temp[j])
            array[k] = temp[i++];
        else
            array[k] = temp[j++];
    }
    while(i <= mid)     array[k++] = temp[i++];
    while(j <= high)    array[k++] = temp[j++];
    delete[] temp;
}

void MergeSort(int array[], int low, int high, int n)
{
    if(low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(array, low, mid, n);
        MergeSort(array, mid+1, high, n);
        Merge(array, low, mid, high, n);
    }
}

void MergeSort2(int array[], int n)
{
    int len = 1;
    while(len < n)
    {
        for(int i = 0; i + len <=n; i += len*2)
        {
            int low = i;
            int mid = i + len - 1;
            int high = i + len * 2 - 1;
            if(high > n - 1)
                high = n - 1;
            Merge(array, low, mid, high, n);
        }
        len *= 2;
    }
}


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


int main(void)
{
    int array[100];
    srand(100);
    for(int i = 0; i < 100; i++)
    {
        array[i] = rand();
        cout << array[i] << "\t";
    }
    cout << endl;
    //InsertSort(array, 100);
    //BinaryInsertSort(array, 100);
    //Print(array, 100);
    // LinkList L;
    // InitList(L, array, 100);
    // PrintListArray(L, 100);
    // cout << endl;
    // ListInsertSort(L, 100);
    // ListSelectSort(L, 100);
    // PrintListArray(L, 100);
    //ShellSort(array, 100);
    //BubbleSort(array, 100);
    time_t start, end;
    start = clock();
    //QuickSort(array, 0, 99);
    //HeapSort(array, 100);
    //MergeSort(array, 0, 99, 100);
    //MergeSort2(array, 100);
    quick_sort(array, 0, 100);
    end = clock();
    cout << end - start << endl;
    Print(array, 100);
    system("pause");
    return 0;
}
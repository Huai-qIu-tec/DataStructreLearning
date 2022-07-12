#include <iostream>
using namespace std;
#define MaxSize 100

template<typename DataType>
class SeqList
{
    public:
    SeqList();
    SeqList(DataType list[], int n);
    bool ListInsert(SeqList& L, int i, DataType e);
    bool ListDelete(SeqList& L, int i, int &e);
    void Print(SeqList& L);

    private:
    DataType data[MaxSize];
    int length;
};

template <typename DataType>
SeqList<DataType>::SeqList(DataType a[], int n)
{
	if (n > MaxSize)	throw "参数非法";
	for (int i = 0; i < n; i++)
	{
		data[i] = a[i];
	}
	length = n;
}


template <typename DataType>
SeqList<DataType>::SeqList()
{
	length = 0;
}


template<typename DataType>
bool SeqList<DataType>::ListInsert(SeqList &L, int i, DataType e)
{
    if(i < 1 || i > length + 1)
        return false;
    if(length >= MaxSize)
        return false;
    for(int j = length; j >= i ; j--)
    {
        data[j] = data[j-1];
    }
    data[i-1] = e;
    length++;
    return true;
}

template<typename DataType>
bool SeqList<DataType>::ListDelete(SeqList &L, int i, int &e)
{
    if(i < 1 || i > L.length)
        return false;
    else
    {
        e = L.data[i-1];
        for(int j = i; j < L.length; j++)
        {
            L.data[j-1] = L.data[j];
        }
        L.length--;
        return true;
    }
}

template<typename DataType>
void SeqList<DataType>::Print(SeqList &L)
{
    for(int i = 0; i < length; i++)
        cout << data[i] << " ";
    cout << endl;
}

int main(void)
{
    int a[5] = {1, 2, 3, 4, 5};

    SeqList <int>L(a, 5);
    L.ListInsert(L, 1, 1);
    int e = -1;
    L.ListDelete(L, 3, e);
    cout << e << endl;
    L.Print(L);
    system("pause");
}
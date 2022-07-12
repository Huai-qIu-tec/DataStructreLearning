#include <iostream>
using namespace std;

int BinarySearch(int array[], int key, int n)
{
    int low = 0;
    int high = n-1;
    int mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(array[mid] < key)
            low = mid + 1;
        else if(array[mid] > key)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}



int main(void)
{
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int index = BinarySearch(array, 3, 10);
    cout << index << endl;
    system("pause");
    return 0;
}

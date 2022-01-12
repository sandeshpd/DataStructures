#include<iostream>
using namespace std;
int getMax(int arr[], int size)
{
    int max = arr[0];
    for(int i = 1;i < size; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
void countingSort(int arr[], int size, int div)
{
    int output[size];
    int count[10] = {0};

    for(int i = 0;i < size; i++)
    count[(arr[i] / div) % 10]++;
    
    for(int i = 1;i < 10; i++)
    count[i]+=count [i - 1];

    for(int i = size-1;i >= 0; i--)
    {
    output[count[(arr[i] / div) % 10] - 1] = arr[i];
    count[(arr[i] / div) % 10]--;
    }
    for(int i = 0;i < size; i++)
    arr[i] = output[i];
}

void radixSort(int arr[], int size)
{
    int m = getMax(arr, size);
    for(int div = 1; m/div > 0; div = div * 10)
    {
        countingSort(arr, size, div);
    }
}

int main()
{
    int size;
    cout<<"\nEnter the size of the array: ";
    cin>>size;
    int arr[size];
    cout<<"\nEnter "<<size<<" elements in random order: ";
    for(int i = 0;i < size; i++)
    {
        cin>>arr[i];
    }
    cout<<"\nBefore sorting: ";
    for(int i = 0;i < size; i++)
    {
        cout<<arr[i]<<"  ";
    }
    radixSort(arr, size);
    cout<<"\nAfter sorting: ";
    for(int i = 0;i < size; i++)
    {
        cout<<arr[i]<<"  ";
    }
    return 0;
}
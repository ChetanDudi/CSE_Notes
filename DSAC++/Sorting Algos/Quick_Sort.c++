//Quick Sort: Pick an element and place it at its correct position in sorted array.
#include <iostream>
#include <vector>
using namespace std;

int Partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while(i <= j)
    {
        while(i <= high && arr[i] <= pivot)
        {
            i++;
        }
        while(j >= low && arr[j] > pivot)
        {
            j--;
        }
        if(i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void QuickSort(vector<int>& arr, int low, int high)
{
    if(low < high)
    {
        int partitionIndex = Partition(arr, low, high);
        QuickSort(arr, low, partitionIndex - 1);
        QuickSort(arr, partitionIndex + 1, high);
    }
}

int main()
{
    vector<int>arr;
    cout<<"Enter the number of elements: ";
    int n;
    cin>>n;
    cout<<"Enter the elements: ";
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    
    QuickSort(arr, 0, n - 1);

    cout<<"Sorted array: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
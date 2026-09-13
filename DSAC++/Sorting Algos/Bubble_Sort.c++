//Bubble Sort: It passes through the list, compares adjacent elements and swaps them if they are in the wrong order. This process is repeated until the list is sorted. This Pushed larger element to the right side of the list in each iteration.

#include <iostream>
#include <vector>
using namespace std;

// O(n^2) time complexity, O(1) space complexity

void BubbleSort(vector<int>& arr)
{
    int n = arr.size();
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
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
    
    BubbleSort(arr);

    cout<<"Sorted array: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
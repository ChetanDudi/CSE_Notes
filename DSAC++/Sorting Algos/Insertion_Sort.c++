//Insertion Sort: It takes an element and places it at its correct position in the sorted part of the array. It is efficient for small data sets and mostly sorted arrays.

#include <iostream>
#include <vector>
using namespace std;

// O(n^2) time complexity, O(1) space complexity


void InsertionSort(vector<int>& arr)
{
    int n = arr.size();
    for(int i=1; i<n; i++)
    {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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
    
    InsertionSort(arr);

    cout<<"Sorted array: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
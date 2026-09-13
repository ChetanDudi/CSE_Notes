//Selection Sort: Swap minimum element with the first element, then find the next minimum and swap it with the second element, and so on.
#include <iostream>
#include <vector>
using namespace std;

// O(n^2) time complexity, O(1) space complexity

void SelectionSort(vector<int>& arr)
{
    int n = arr.size();
    for(int i=0; i<n-1; i++)
    {
        int minIndex = i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
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
    SelectionSort(arr);
    cout<<"Sorted array: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

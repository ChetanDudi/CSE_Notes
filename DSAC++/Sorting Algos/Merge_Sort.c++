//Merge Sort: This sorts array by using divide and conquer technique. It divides the array into two halves, sorts them and then merges them back together. It is a stable sort and works well for large datasets.
#include <iostream>
#include <vector>
using namespace std;

//Overall time complexity of merge sort is O(nlogn) and space complexity is O(n)

//O(nlogn) time complexity
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left=low;
    int right=mid+1;

    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for(int k=low; k<=high; k++)
    {
        arr[k]=temp[k-low];
    }
}

//O(nlogn) time complexity
void MergeSort(vector<int> &arr, int low, int high)
{
    if(low>=high)
    {
        return;
    }
    int mid=low+(high-low)/2;
    MergeSort(arr,low,mid);
    MergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
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
    
    MergeSort(arr,0,n-1);

    cout<<"Sorted array: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
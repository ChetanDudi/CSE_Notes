#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int fn(int arr[],int n)
{
    int first=arr[0];
    int second=arr[1];
    for(int i=0;i<n;i++)
    {
        if(arr[i]<first)
        {
            first=arr[i];
        }
        if(arr[i]>first && arr[i]<second)
        {
            second=arr[i];
        }
    }
    return second;
}

int main()
{
    int arr[5];
    cout<<"Enter 5 numbers: ";
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
    }
    cout<<fn(arr,5);
}
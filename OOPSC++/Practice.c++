#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string s="racecar";
    string rs=s;
    reverse(rs.begin(),rs.end());
    if(s==rs)
    {
        cout<<"palindrome";
    }
    else
    {
        cout<<"not a palindrome";
    }
    return 0;

}
#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

//Kadane's algorithm
int MaxSubarraySum(int arr[], int n) 
{
    int current_sum=0;
    int max_sum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        current_sum+=arr[i];
        if(current_sum > max_sum)
        {
            max_sum = current_sum;
        }
        if(current_sum < 0)
        {
            current_sum = 0;
        }
    }
    return max_sum;
}

//Moore's Voting Algorithm
int findMajorityElement(int arr[], int n) 
{
    int fre = 1;
    int majorityElement = arr[0];
    for(int i = 0; i < n; i++) 
    {
        if(arr[i] == majorityElement) 
        {
            fre++;
        } 
        else 
        {
            fre--;
        }
        if(fre == 0) 
        {
            majorityElement = arr[i];
            fre = 1;
        }
    }
    return majorityElement;
}

//Peak element(element greater than its neighbors)
    int findPeakElement(vector<int>& nums) 
    {
        if(nums.size()==1)
        {
            return 0;
        }
        //Add padding in the starting and ending of the vector
        nums.insert(nums.begin(),INT_MIN); 
        nums.push_back(INT_MIN); 
       int start=1,end=nums.size()-2;
       while(start<=end)
       {
            int mid=start+(end-start)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
            {
                return mid-1;//mid-1 because we added padding
            }
            else if(nums[mid]<nums[mid-1])
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
       }
       return -1;
    }

//Reverse words in string(first reverse the whole string then reverse each word)
    void reverseWords(string &s) 
    {
        int n=s.length();
        //Reverse the whole string
        reverse(s.begin(),s.end());
        int start=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                //Reverse each word
                reverse(s.begin()+start,s.begin()+i);
                start=i+1;
            }
        }
        //Reverse the last word
        reverse(s.begin()+start,s.end());
    }

//Sieve of Eratosthenes
    vector<int> sieveOfEratosthenes(int n) 
    {
        vector<int> primes;
        vector<bool> isPrime(n+1,true);
        isPrime[0]=isPrime[1]=false; //0 and 1 are not prime numbers
        for(int i=2;i*i<=n;i++)
        {
            if(isPrime[i])
            {
                for(int j=i*i;j<=n;j+=i)
                {
                    isPrime[j]=false;
                }
            }
        }
        for(int i=2;i<=n;i++)
        {
            if(isPrime[i])
            {
                primes.push_back(i);
            }
        }
        return primes;
    }

//Euclid's Algorithm to find GCD/HCF of two numbers
    int gcd(int a,int b)
    {
        if(b==0)
        {
            return a;
        }
        return gcd(b,a%b);
    }

//Spiral Matrix
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> result;
        int top=0,bottom=matrix.size()-1;
        int left=0,right=matrix[0].size()-1;
        while(top<=bottom && left<=right)
        {
            //Traverse from left to right
            for(int i=left;i<=right;i++)
            {
                result.push_back(matrix[top][i]);
            }
            top++;
            //Traverse from top to bottom
            for(int i=top;i<=bottom;i++)
            {
                result.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom)
            {
                //Traverse from right to left
                for(int i=right;i>=left;i--)
                {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right)
            {
                //Traverse from bottom to top
                for(int i=bottom;i>=top;i--)
                {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return result;
    }

//Subarray sum using Prefix sum
    int subarraySum(vector<int>& nums) 
    {
        int prefixSum[nums.size()+1];
        prefixSum[0]=0;
        for(int i=1;i<=nums.size();i++)
        {
            prefixSum[i]=prefixSum[i-1]+nums[i-1];
        }
        //sum of subarray from index i to j = prefixSum[j+1]-prefixSum[i]
        int i,j;
        return prefixSum[j+1]-prefixSum[i];
    }

//Print all subsets using recursion
    vector<vector<int>> print(vector<int>&nums,vector<vector<int>>&ans,int i,vector<int>& subset)
    {
        if(i==nums.size())
        {
            ans.push_back(subset);
            return ans;
        }
        subset.push_back(nums[i]);
        print(nums,ans,i+1,subset);
        subset.pop_back();
        print(nums,ans,i+1,subset);
        return ans;
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>>allsubsets;
        vector<int>one_subset;
        int i=0;
        return print(nums,allsubsets,i,one_subset);    
    }

//Level Order Traversal of Binary Tree
    struct Node
    {
        int data;
        Node *left;
        Node *right;
        Node(int val)
        {
            data=val;
            left=NULL;
            right=NULL;
        }
    };
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>> result;
        if(root==NULL)
        {
            return result;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int> level;
            for(int i=0;i<size;i++)
            {
                Node* node=q.front();
                q.pop();
                level.push_back(node->data);
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            result.push_back(level);
        }
        return result;
    }

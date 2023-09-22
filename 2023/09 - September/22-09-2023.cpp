/*

Author : Manas Rawat
Date : 22/09/2023
Problem : First and last occurrences of x
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1
Video Solution : NA

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        vector<int> ans(2);
        ans[0] = lower_bound(arr, arr + n, x) - arr;
        
        if(arr[ans[0]] != x)
            return {-1, -1};
            
        ans[1] = upper_bound(arr, arr + n, x) - arr;
        --ans[1];
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends
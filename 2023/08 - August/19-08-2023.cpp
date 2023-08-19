/*

Author : Manas Rawat
Date : 19/08/2023
Problem : Subarray with given sum
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        if(n == 1){
            if(arr[0] == s)
                return {1, 1};
            else
                return {-1};
        }
        
        int r = 0;
        int l = 0;
        
        long long sum = arr[0];
        
        while(r < n){
            if(sum < s){
                sum += arr[++r];
            }
            else if(sum > s){
                if(l == r){
                    ++l; ++r;
                    sum = arr[l];
                }
                else{
                    sum -= arr[l++];
                }
            }
            else{
                return {l + 1, r + 1};
            }
        }
        
        return {-1};
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
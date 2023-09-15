/*

Author : Manas Rawat
Date : 15/09/2023
Problem : Partition Equal Subset Sum
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
Video Solution : NA

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        int sum = 0;
        for(int i = 0; i < n; i++)  
            sum += arr[i];
            
        vector<vector<int>> dp(n + 1, vector<int> (sum + 1, 0));
        if(!(sum & 1)){
            dp[n][sum / 2] = 1;
        }
        else{
            return 0;
        }
        
        for(int i = n - 1; i > -1; i--){
            for(int j = 0; j < sum + 1; j++){
                bool take, notake;
                
                take = notake = 0;
                
                if(j + arr[i] <= sum)
                    take = dp[i + 1][j + arr[i]];
                notake = dp[i + 1][j];
                
                dp[i][j] = take || notake;
            }
        }
        
        return dp[0][0];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
/*

Author : Manas Rawat
Date : 25/10/2023
Problem : Knapsack with Duplicate Items
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
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
    int knapSack(int N, int W, int val[], int wt[])
    {
        int dp[N + 1][W + 1];
        
        for(int i = 0; i < W + 1; i++)
            dp[N][i] = 0;
        
        for(int i = N - 1; i > -1; i--){
            for(int j = W; j > -1; j--){
                int take, notake;
                
                take = notake = 0;
                
                if(j + wt[i] <= W)
                    take = val[i] + dp[i][j + wt[i]];
                    
                notake = dp[i + 1][j];
                
                dp[i][j] = max(take, notake);
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
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends
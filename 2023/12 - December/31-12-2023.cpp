/*

Author : Manas Rawat
Date : 31/12/2023
Problem : New Year Resolution
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/good-by-2023/1
Video Solution : https://youtu.be/xqq5tVLOz3A

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    public:
    int isPossible(int N , int coins[]) 
    {
        int MAX = accumulate(coins, coins + N, 0LL) + 1;
        
        vector<vector<int>> dp(N + 1, vector<int> (MAX, 0));
        
        for(int i = 20; i < MAX; i += 20)
            dp[N][i] = 1;
        for(int i = 24; i < MAX; i += 24)
            dp[N][i] = 1;
        if(2024 < MAX)
            dp[N][2024] = 1;
        
        for(int i = N - 1; i > -1; i--){
            for(int j = 0; j < MAX; j++){
                int take, notake;
                take = notake = 0;
                
                notake = dp[i + 1][j];
                
                if(coins[i] + j < MAX)
                    take = dp[i + 1][j + coins[i]];
                    
                dp[i][j] = max(take, notake);
            }
        }
        
        return dp[0][0];
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends
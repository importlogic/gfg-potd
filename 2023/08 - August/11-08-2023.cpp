/*

Author : Manas Rawat
Date : 11/08/2023
Problem : Coin Change
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/coin-change2448/1
Video Solution : https://youtu.be/rXms3YKTu2k

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {
        vector<vector<long long>> dp(N, vector<long long> (sum + 1, 0));
        for(int i = 0; i < N; i++)
            dp[i][0] = 1;
            
        for(int i = 0; i < N; i++){
            for(int j = 1; j < sum + 1; j++){
                long long take, notake;
                take = notake = 0;
                
                if(j >= coins[i])
                    take = dp[i][j - coins[i]];
                    
                if(i > 0)
                    notake = dp[i - 1][j];
                    
                dp[i][j] = take + notake;
            }
        }
        
        return dp[N - 1][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends
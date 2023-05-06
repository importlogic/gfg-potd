/*

Author : Manas Rawat
Date : 06/05/2023
Problem : Another Coin Change Problem
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/09b910559335521654aa2909f86f893447d8f5ba/1
Video Solution : https://youtu.be/ax-CV2a3Zj8

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

int dp[101][1001][101];

class Solution {
  public:
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        for(int i = 0; i < N + 1; i++){
            for(int j = 0; j < target + 1; j++){
                for(int k = 0;k < K + 1; k++){
                    if(i == 0){
                        dp[i][j][k] = j == 0 and k == 0;
                        continue;
                    }
                    
                    int x, y;
                    x = y = 0;
                    
                    x = dp[i - 1][j][k];
                    if(j >= coins[i - 1] and k)
                        y = dp[i][j - coins[i - 1]][k - 1];
                    
                    dp[i][j][k] = x + y;
                }
            }
        }
        
        return dp[N][target][K];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends
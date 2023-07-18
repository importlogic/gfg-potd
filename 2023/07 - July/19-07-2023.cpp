/*

Author : Manas Rawat
Date : 19/07/2023
Problem : Longest Palindromic Subsequence
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1
Video Solution : https://youtu.be/rtnw4B4kguE

*/


//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        int n = A.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
        
        for(int i = n - 1; i > -1; i--){
            for(int j = i + 1; j < n; j++){
                if(A[i] == A[j]){
                    if(i == j - 1)
                        dp[i][j] = 2;
                    else
                        dp[i][j] = 2 + dp[i + 1][j - 1];
                }
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        
        return dp[0][n - 1];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
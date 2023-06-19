/*

Author : Manas Rawat
Date : 14/02/2023
Problem : Walls Coloring
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/51b266505221b97522b1d2c86ddad1868a54831b/1
Video Solution : https://youtu.be/knjVGuQFYzo

*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int n) {
        int dp[n + 1][3];
        
        for(int i = 0; i < 3; i++) dp[n][i] = 0;
        
        for(int i = n - 1; i > -1; i--){
            for(int j = 0; j < 3; j++){
                dp[i][j] = 1e7;
                for(int k = 0; k < 3; k++){
                    if(j != k) // condition to check that adjacent colors are not same
                        dp[i][j] = min(dp[i][j], colors[i][j] + dp[i + 1][k]);
                }
            }
        }
        
        int ans = 1e7;
        
        for(int i = 0; i < 3; i++) ans = min(ans, dp[0][i]);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends
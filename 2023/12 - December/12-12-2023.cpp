/*

Author : Manas Rawat
Date : 12/12/2023
Problem : Gold Mine Problem
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/gold-mine-problem2608/1
Video Solution : https://youtu.be/9wLaqTZipP0

*/


 Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<vector<int>> dp(n, vector<int> (m));
        
        for(int i = 0; i < n; i++){
            dp[i][m - 1] = M[i][m - 1];
        }
        
        for(int j = m - 2; j > -1; j--){
            for(int i = 0; i < n; i++){
                dp[i][j] = dp[i][j + 1];
                
                if(i > 0)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + 1]);
                if(i < n - 1)
                    dp[i][j] = max(dp[i][j], dp[i + 1][j + 1]);
                    
                dp[i][j] += M[i][j];
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++)
            ans = max(ans, dp[i][0]);
            
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
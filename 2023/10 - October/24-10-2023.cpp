/*

Author : Manas Rawat
Date : 24/10/2023
Problem : Palindromic Partitioning
Difficulty : Hard
Problem Link : https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
Video Solution : NA

*/


//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string str)
    {
        int n = str.size();
        
        vector<int> dp(n + 1);
        vector<vector<bool>> ok(n, vector<bool> (n));
        
        for(int i = n - 1; i > -1; i--){
            for(int j = i; j < n; j++){
                if(i == j or i == j - 1){
                    ok[i][j] = str[i] == str[j];
                }
                else if(str[i] == str[j]){
                    ok[i][j] = ok[i + 1][j - 1];
                }
                else{
                    ok[i][j] = 0;
                }
            }
        }
        
        dp[n] = 0;
        
        for(int i = n - 1; i > -1; i--){
            int ans = 1e9;
            
            for(int j = i; j < n; j++){
                if(ok[i][j])
                    ans = min(ans, 1 + dp[j + 1]);
            }
            
            if(ok[i][n - 1])
                ans = 0;
                
            dp[i] = ans;
        }
        
        return dp[0];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
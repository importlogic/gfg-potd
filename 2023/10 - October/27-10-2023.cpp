/*

Author : Manas Rawat
Date : 27/10/2023
Problem : Minimum Deletions
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/minimum-deletitions1648/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int minimumNumberOfDeletions(string s) { 
        int n = s.size();
        int dp[n][n];
        
        for(int i = n - 1; i > -1; i--){
            for(int j = i; j < n; j++){
                if(i == j){
                    dp[i][j] = 0;
                    continue;
                }
                
                if(s[i] == s[j]){
                    if(j - i == 1)
                        dp[i][j] = 0;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[0][n - 1];
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends
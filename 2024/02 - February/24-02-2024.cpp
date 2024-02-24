/*

Author : Manas Rawat
Date : 24/02/2024
Problem : Maximum Sum Problem
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/maximum-sum-problem2211/1
Video Solution : NA

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        int maxSum(int n)
        {
            vector<int> dp(n + 1, 0);
            dp[1] = 1;
            
            for(int i = 2; i < n + 1; i++){
                dp[i] = max(i, dp[i / 2] + dp[i / 3] + dp[i / 4]);
            }
            
            return dp[n];
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends

/*

Author : Manas Rawat
Date : 16/08/2023
Problem : Nth catalan number
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/nth-catalan-number0817/1
Video Solution : https://youtu.be/7J2OmTt3PC8

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        const int mod = 1e9 + 7;
        
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        
        for(int i = 1; i < n + 1; i++){
            for(int j = 0; j < i; j++){
                dp[i] = (dp[i] + (dp[j] * dp[i - j - 1]) % mod) % mod; 
            }
        }
        
        return dp[n];
    }
};


//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends
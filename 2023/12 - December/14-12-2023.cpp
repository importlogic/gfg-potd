/*

Author : Manas Rawat
Date : 14/12/2023
Problem : Painting the Fence
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/painting-the-fence3727/1
Video Solution : https://youtu.be/wUrfLCOySG0

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
        if(n == 1)
            return k;
            
        vector<vector<long long>> dp(n + 1, vector<long long> (2, 1));
        const long long mod = 1e9 + 7;
        
        for(int i = n - 1; i > 0; i--){
            dp[i][0] = (((k - 1) * dp[i + 1][0]) % mod + dp[i + 1][1]) % mod;
            
            dp[i][1] = ((k - 1) * dp[i + 1][0]) % mod;
        }
        
        return dp[0][0] = (k * dp[1][0]) % mod;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends
/*

Author : Manas Rawat
Date : 05/01/2024
Problem : Count possible ways to construct buildings
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/count-possible-ways-to-construct-buildings5007/1
Video Solution : https://youtu.be/3yApl-LLGc4

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    const long long mod = 1e9 + 7;
	    vector<vector<long long>> dp(N + 1, vector<long long> (2, 1));
	    
	    for(int i = N - 1; i > -1; i--){
	        dp[i][1] = dp[i + 1][0];
	        
	        int make, nomake;
	        make = dp[i + 1][1];
	        nomake = dp[i + 1][0];
	        
	        dp[i][0] = (make + nomake) % mod;
	    }
	    
	    return (dp[0][0] * dp[0][0]) % mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
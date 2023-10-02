/*

Author : Manas Rawat
Date : 02/10/2023
Problem : Number of distinct subsequences
Difficulty : Hard
Problem Link : https://practice.geeksforgeeks.org/problems/number-of-distinct-subsequences0909/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    int n = s.size();
	    
	    const long long mod = 1e9 + 7;
	    
	    vector<long long> pos(26, n), dp(n + 1, 0);
	    long long ans = 1;
	    
	    for(int i = n - 1; i > -1; i--){
	        long long cur = dp[i + 1];
	        if(pos[s[i] - 'a'] < n)
	            cur = (cur - dp[pos[s[i] - 'a'] + 1] + mod) % mod;
	        else
	            cur = (cur + 1) % mod;
	            
	        dp[i] = (cur + dp[i + 1]) % mod;
	        pos[s[i] - 'a'] = i;
	    }
	    
	    return dp[0] + 1;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends
/*

Author : Manas Rawat
Date : 22/02/2024
Problem : Distinct occurrences
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/distinct-occurrences/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int subsequenceCount(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        
        const int mod = 1e9 + 7;
        
        vector<vector<int>> dp(n + 1, vector<int> (m + 1));
        for(int i = 0; i < n + 1; i++)
            dp[i][m] = 1;
        
        for(int i = n - 1; i > -1; i--){
            for(int j = m - 1; j > -1; j--){
                dp[i][j] = 0;
                
                if(s[i] == t[j])
                    dp[i][j] = dp[i + 1][j + 1];
                    
                dp[i][j] = (dp[i][j] + dp[i + 1][j]) % mod;
            }
        }
        
        return dp[0][0];
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends


/*

Author : Manas Rawat
Date : 18/07/2023
Problem : Longest Repeating Subsequence
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
Video Solution : https://youtu.be/bv4U0q_-bEw

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int n = str.size();
		    
		    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
		    
		    for(int i = n - 1; i > -1; i--){
		        for(int j = n - 1; j > -1; j--){
		            int movea, moveb;
                    movea = dp[i + 1][j];
                    moveb = dp[i][j + 1];
		            
		            int take = 0;
		            if(i != j and str[i] == str[j])
		                take = 1 + dp[i + 1][j + 1];
		                
		            dp[i][j] = max({movea, moveb, take});
		        }
		    }
		    
		    return dp[0][0];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
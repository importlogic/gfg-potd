/*

Author : Manas Rawat
Date : 14/09/2023
Problem : Perfect Sum Problem
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
	    const int mod = 1e9 + 7;
	    
        vector<vector<long long>> dp(n + 1, vector<long long> (sum + 1, 0));
        dp[n][0] = 1;
        
        for(int i = n - 1; i > -1; i--){
            for(int j = 0; j < sum + 1; j++){
                long long take, notake;
                take = notake = 0;
                
                if(j >= arr[i])
                    take = dp[i + 1][j - arr[i]];
                notake = dp[i + 1][j];
                
                dp[i][j] = (take + notake) % mod;
            }
        }
        
        return dp[0][sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
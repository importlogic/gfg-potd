/*

Author : Manas Rawat
Date : 23/10/2023
Problem : Maximum sum increasing subsequence
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int> dp(n + 1, 0);
	    
	    for(int i = n - 1; i > -1; i--){
            int take = arr[i];
	        
	        for(int j = i + 1; j < n; j++){
	            if(arr[j] > arr[i])
	                take = max(take, arr[i] + dp[j]);
	        }
	        
	        dp[i] = take;
	    }
	    
	    return *max_element(dp.begin(), dp.end());
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
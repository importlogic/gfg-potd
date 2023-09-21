/*

Author : Manas Rawat
Date : 21/09/2023
Problem : Stickler Thief
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n + 1, 0);
        
        for(int i = n - 1; i > -1; i--){
            int take, notake;
            
            take = arr[i];
            if(i + 2 <= n)
                take += dp[i + 2];
                
            notake = dp[i + 1];
            
            dp[i] = max(take, notake);
        }
        
        return dp[0];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends
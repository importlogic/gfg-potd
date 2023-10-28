/*

Author : Manas Rawat
Date : 28/10/2023
Problem : Bleak Numbers
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/bleak-numbers1552/1
Video Solution : NA

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	int is_bleak(int n)
	{
	    for(int i = 0 ; i < 32; i++){
	        if(n - i > -1 and __builtin_popcount(n - i) == i)
	            return 0;
	    }
	    
	    return 1;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends
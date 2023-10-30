/*

Author : Manas Rawat
Date : 30/10/2023
Problem : Sum of XOR of all pairs
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/sum-of-xor-of-all-pairs0723/1
Video Solution : NA

*/


//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	vector<int> f(20, 0);
    	for(int i = 0; i < n; i++){
    	    int cb = 1;
    	    for(int j = 0; j < 20; j++){
    	        if(arr[i] & cb)
    	            ++f[j];
    	            
    	        cb <<= 1;
    	    }
    	}
    	
    	long long ans = 0;
    	
    	long long cb = 1;
    	for(int i = 0; i < 20; i++){
    	    ans += cb * f[i] * (n - f[i]);
    	    cb <<= 1;
    	}
    	
    	return ans;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends
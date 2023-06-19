/*

Author : Manas Rawat
Date : 10/03/2023
Problem : Maximum Triplet product
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/d54c71dc974b7db3a200eb63f34e3d1cba955d86/1
Video Solution : https://youtu.be/p_ZDHaTLcws

*/


//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
        long long nin[3], nax[3];
        nin[0] = nin[1] = nin[2] = 1e10;
        nax[0] = nax[1] = nax[2] = -1e10;
        
        for(int i = 0; i < n; i++){
            long long current = arr[i];
            
            for(int j = 0; j < 3; j++){
                if(current < nin[j])
                    swap(nin[j], current);
            }
            
            current = arr[i];
            
            for(int j = 0; j < 3; j++){
                if(current > nax[j])
                    swap(nax[j], current);
            }
        }
        
        long long ans = max(nin[0] * nin[1] * nax[0], nax[0] * nax[1] * nax[2]);
    	
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
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends
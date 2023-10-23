/*

Author : __
Date : 22/10/2023
Problem : Number of paths
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/number-of-paths0926/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution
{
    public:
    long long numberOfPaths(int M, int N)
    {
        int n=M+N-2;
        int r=M-1;
        int modd=1e9+7;
        long long int paths=1;
        for(int i=0; i<r; i++)
        {
            paths = (paths%modd * ((n - i)%modd))%modd;
            paths = (paths%modd * inverse(i+1, modd))%modd;
        }
        return paths;
    }

    long long power(long long x, unsigned int y, int p)
    {
        long long res = 1; 
        x = x % p; 
        while (y > 0) 
        {
            if (y & 1)
                res = (res*x) % p;
            y = y>>1; 
            x = (x*x) % p;
        }
        return res;
    }

    long long inverse(int n, int p)
    {
        return power(n, p-2, p);
    }
};


//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N, M;
		cin>>M>>N;
		Solution ob;
	    cout << ob.numberOfPaths(M, N)<<endl;
	}
    return 0;
}
// } Driver Code Ends
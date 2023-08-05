/*

Author : Manas Rawat
Date : 05/08/2023
Problem : Chocolate Distribution Problem
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
Video Solution : https://youtu.be/c163Cpg5bBU

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(), a.end());
        long long ans = 1e9;
        
        for(int i = m - 1; i < n; i++){
            ans = min(ans, a[i] - a[i - (m - 1)]);
        }
        
        return ans;
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends
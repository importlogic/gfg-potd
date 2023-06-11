/*

Author : Manas Rawat
Date : 11/06/2023
Problem : Adding Ones
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/adding-ones3628/1
Video Solution : https://youtu.be/WVrw3bi0M8E

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    void update(int a[], int n, int updates[], int k)
    {
        vector<int> dx(n, 0);
        
        for(int i = 0; i < k; i++)
            dx[updates[i] - 1]++;
            
        int toadd = 0;
        
        for(int i = 0; i < n; i++){
            toadd += dx[i];
            a[i] += toadd;
        }
    }
};

//{ Driver Code Starts.
int main()
{
	int t; cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a[n]={0}, updates[k]={0};
		for(int i = 0; i < k; i++)
		cin>>updates[i];
		Solution ob;
		ob.update(a, n, updates, k);
		
		for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
		
		cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends
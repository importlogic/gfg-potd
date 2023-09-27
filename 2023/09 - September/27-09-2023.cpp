/*

Author : Manas Rawat
Date : 27/09/2023
Problem : Find the closest pair from two arrays
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/find-the-closest-pair-from-two-arrays4215/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        int best = 1e9;
        vector<int> ans(2);
        
        int i = 0;
        int j = m - 1;
        
        while(i < n and j > -1){
            if(abs(arr[i] + brr[j] - x) < best){
                best = abs(arr[i] + brr[j] - x);
                ans[0] = arr[i];
                ans[1] = brr[j];
            }
            
            if(arr[i] + brr[j] > x)
                --j;
            else if(arr[i] + brr[j] < x)
                ++i;
            else
                break;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends
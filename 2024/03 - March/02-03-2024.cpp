/*

Author : Manas Rawat 
Date : 02/03/2024
Problem : First element to occur k times
Difficulty : Easy 
Problem Link : https://www.geeksforgeeks.org/problems/first-element-to-occur-k-times5150/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int firstElementKTime(int n, int k, int a[])
    {
        vector<int> f(201, 0);
        
        for(int i = 0; i < n; i++) {
            ++f[a[i]];
            
            if(f[a[i]] == k)
                return a[i];
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution ob;
	    cout<<ob.firstElementKTime(n, k, a)<<endl;
	}
	
	return 0;
}
// } Driver Code Ends

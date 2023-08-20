/*

Author : Manas Rawat
Date : 20/08/2023
Problem : Number of occurrence
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1
Video Solution : https://youtu.be/oS_6D5emTEE

*/


//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    int first = lower_bound(arr, arr + n, x) - arr;
	    int last = upper_bound(arr, arr + n, x) - arr;
	    
	    if(first == n or arr[first] != x)
	        return 0;
	    
	    return last - first;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
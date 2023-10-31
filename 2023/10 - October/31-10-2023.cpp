/*

Author : Manas Rawat
Date : 31/10/2023
Problem : Move all zeroes to end of array
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    int index = 0;
	    
	    for(int i = 0; i < n; i++){
	        if(arr[i])
	            arr[index++] = arr[i];
	    }
	    
	    while(index < n)
	        arr[index++] = 0;
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
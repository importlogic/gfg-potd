/*

Author : Manas Rawat
Date : 17/12/2023
Problem : Max Sum without Adjacents
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1
Video Solution : https://youtu.be/TeDartJOsc0

*/


//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    int next_0, next_1;
	    next_0 = next_1 = 0;
	    
	    for(int i = n - 1; i > -1; i--){
	        int cur_0 = max(arr[i] + next_1, next_0);
	        int cur_1 = next_0;
	        
	        next_0 = cur_0;
	        next_1 = cur_1;
	    }
	    
	    return next_0;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
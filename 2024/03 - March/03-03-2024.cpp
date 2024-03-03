/*

Author : Manas Rawat 
Date : 03/03/2024
Problem : Largest Number formed from an Array
Difficulty : Medium 
Problem Link : https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	string printLargest(int n, vector<string> &arr) {
	    sort(arr.begin(), arr.end(), [](string &x, string &y) {
	        return x + y > y + x;
	    });
	    
	    string ans = "";
	    
	    for(auto i : arr){
	        for(auto j : i) {
	            if(ans.size() == 0 and j == '0')
	                continue;
	               
	            ans += j;
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(n, arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends

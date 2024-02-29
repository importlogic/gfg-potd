/*

Author : Manas Rawat 
Date : 29/02/2024
Problem : Sum of bit differences
Difficulty : Medium 
Problem Link : https://www.geeksforgeeks.org/problems/sum-of-bit-differences2937/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
	long long sumBitDifferences(int arr[], int n) {
        long long ans = 0;
        
        for(int i = 31; i > -1; i--) {
            long long bit_ans = 0;
            
            for(int j = 0; j < n; j++) {
                bit_ans += (arr[j] >> i) & 1;
            }
            
            ans += 2LL * bit_ans * (n - bit_ans);
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
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends

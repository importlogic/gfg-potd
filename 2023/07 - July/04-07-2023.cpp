/*

Author : Manas Rawat
Date : 04/07/2023
Problem : Count the subarrays having product less than k
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1
Video Solution : https://youtu.be/LO3R_CBNK2w

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    long long countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long p = 1;
        long long res = 0;
        for (int start = 0, end = 0; end < n; end++) {
    
            // Move right bound by 1 step. Update the product.
            p *= a[end];
    
            // Move left bound so guarantee that p is again
            // less than k.
            while (start < end && p >= k) p /= a[start++];
    
            // If p is less than k, update the counter.
            // Note that this is working even for (start == end):
            // it means that the previous window cannot grow
            // anymore and a single array element is the only
            // addendum.
            if (p < k) {
                int len = end - start + 1;
                res += len;
            }
        }
    
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends

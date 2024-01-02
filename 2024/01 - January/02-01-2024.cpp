/*

Author : Manas Rawat
Date : 02/01/2024
Problem : Largest Sum Subarray of Size at least K
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k3121/1
Video Solution : https://youtu.be/u_hxfNXqb3g

*/


//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        vector<long long> dp(n + 1, 0);
        
        for(int i = n - 1; i > -1; i--){
            dp[i] = a[i] + dp[i + 1];
            dp[i] = max(dp[i], 0LL);
        }
            
        long long ans = -1e18;
        
        long long cur_sum = 0;
        for(int i = 0; i < k; i++)
            cur_sum += a[i];
        
        for(int i = k; i < n; i++){
            long long sum = cur_sum + dp[i];
            ans = max(ans, sum);
            
            cur_sum += a[i];
            cur_sum -= a[i - k]; 
        }
        
        return max(ans, cur_sum);
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
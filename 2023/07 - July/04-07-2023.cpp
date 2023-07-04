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
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int l, r, ans;
        l = r = ans = 0;
        long long product = a[0];
        
        while(r < n){
            if(product < k){
                ans += (r - l + 1);
                ++r;
                if(r < n)
                    product *= a[r];
            }
            else{
                product /= a[l];
                
                if(l == r){
                    ++r;
                    if(r < n)
                        product *= a[r];
                }
                
                ++l;
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
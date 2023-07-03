/*

Author : Manas Rawat
Date : 03/07/2023
Problem : Maximum Index
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/maximum-index3307/1
Video Solution : https://youtu.be/a04VRXkdMx8

*/


//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        vector<int> prefix(n), suffix(n);
        prefix[0] = arr[0];
        suffix[n - 1] = arr[n - 1];
        
        for(int i = 1; i < n; i++){
            prefix[i] = min(prefix[i - 1], arr[i]);
            suffix[n - i - 1] = max(suffix[n - i], arr[n - i - 1]);
        }
        
        int i, j, ans;
        i = j = ans = 0;
        
        while(j < n){
            if(prefix[i] <= suffix[j]){
                ans = max(ans, j - i);
                ++j;
            }
            else{
                ++i;
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
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
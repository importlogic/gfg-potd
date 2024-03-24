/*

Author : Manas Rawat 
Date : 23/03/2024
Problem : Fibonacci series up to Nth term
Difficulty : Easy 
Problem Link : https://www.geeksforgeeks.org/problems/fibonacci-series-up-to-nth-term/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Series(int n) {
        const long long mod = 1e9 + 7;
        vector<int> ans = {0, 1};
            
        for(int i = 2; i < n + 1; i++){
            long long val = ans[i - 1];
            val = (val + ans[i - 2]) % mod;
            ans.push_back(val);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends

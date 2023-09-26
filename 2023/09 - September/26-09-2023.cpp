/*

Author : Manas Rawat
Date : 26/09/2023
Problem : Find All Four Sum Numbers
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int K) {
        sort(arr.begin(), arr.end());
        
        unordered_map<int,int> f;
        for(auto i : arr)
            ++f[i];
            
        int n = arr.size();
        set<vector<int>> t;
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    int need = K - (arr[i] + arr[j] + arr[k]);
                    
                    if(need < arr[k])
                        continue;
                        
                    int cnt = (arr[i] == need) + (arr[j] == need) + (arr[k] == need);
                    
                    if(f.count(need) and f[need] - cnt > 0){
                        t.insert({arr[i], arr[j], arr[k], need});
                    }
                }
            }
        }
        
        for(auto i: t)
            ans.emplace_back(i);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
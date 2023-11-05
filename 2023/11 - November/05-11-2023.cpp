/*

Author : Manas Rawat
Date : 05/11/2023
Problem : Top K Frequent Elements in Array - I
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        vector<int> f(1e5 + 10, 0);
        
        for(auto i : nums)
            ++f[i];
            
        vector<pair<int,int>> list;
        
        for(int i = 0; i < 1e5 + 10; i++){
            if(f[i])
                list.emplace_back(i, f[i]);
        }
        
        sort(list.begin(), list.end(), [](pair<int,int> &a, pair<int,int> &b){
            if(a.second == b.second)
                return a.first > b.first;
            return a.second > b.second;
        });
        
        vector<int> ans(k);
        
        for(int i = 0; i < k; i++){
            ans[i] = list[i].first;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
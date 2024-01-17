/*

Author : Manas Rawat
Date : 17/01/2024
Problem : All Unique Permutations of an array
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/1
Video Solution : https://youtu.be/ZajftAXBmcI

*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        vector<vector<int>> ans;
        vector<int> cur, taken(n, 0);
        
        function<void(int)> helper = [&](int p) {
            if(p == n){
                ans.push_back(cur);
                return;
            }  
            
            vector<int> cur_taken(11, 0);
            
            for(int i = 0; i < n; i++){
                if(!taken[i] and !cur_taken[arr[i]]){
                    cur_taken[arr[i]] = 1;
                    taken[i] = 1;
                    cur.push_back(arr[i]);
                    helper(p + 1);
                    cur.pop_back();
                    taken[i] = 0;
                }
            }
        };
        
        helper(0);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
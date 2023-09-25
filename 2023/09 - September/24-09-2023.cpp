/*

Author : Manas Rawat
Date : 24/09/2023
Problem : Find duplicates in an array
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        vector<int> vis(n, 0);
        
        for(int i = 0; i < n; i++){
            if(!vis[arr[i]])
                vis[arr[i]] = 1;
            else
                vis[arr[i]] = 2;
        }
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            if(vis[i] > 1)
                ans.push_back(i);
        }
        
        if(ans.size() == 0)
            ans = {-1};
            
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
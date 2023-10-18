/*

Author : Manas Rawat
Date : 18/10/2023
Problem : Eventual Safe States
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/eventual-safe-states/1
Video Solution : NA

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        vector<int> out(n, 0);
        
        vector<vector<int>> tg(n);
        
        for(int i = 0; i < n; i++){
            out[i] = adj[i].size();
            
            for(auto c : adj[i])
                tg[c].push_back(i);
        }
        
        vector<int> ans;
        queue<int> q;
        
        for(int i = 0; i < n; i++){
            if(!out[i]){
                ans.push_back(i);
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto child : tg[node]){
                --out[child];
                
                if(!out[child]){
                    q.push(child);
                    ans.push_back(child);
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
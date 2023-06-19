/*

Author : Manas Rawat
Date : 26/02/2023
Problem : Number of Good Components
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/1a4b617b70f0142a5c2b454e6fbe1b9a69ce7861/1
Video Solution : https://youtu.be/pwOZPTE9c0k

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int vertices;
set<pair<int,int>> edges;

void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj){
    ++vertices;
    vis[node] = 1;
    
    for(auto child : adj[node]){
        edges.insert({node, child});
        edges.insert({child, node});
        
        if(!vis[child])
            dfs(child, vis, adj);
    }
}


class Solution {
  public:
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        int ans = 0;
        
        vector<bool> vis(V + 1, 0);
        
        for(int i = 1; i < V + 1; i++){
            if(!vis[i]){
                vertices = 0;
                edges.clear();
                
                dfs(i, vis, adj);
                
                vertices *= (vertices - 1); // n * (n - 1)
                vertices >>= 1; // n / 2
                
                ans += vertices == (edges.size() >> 1);
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
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends
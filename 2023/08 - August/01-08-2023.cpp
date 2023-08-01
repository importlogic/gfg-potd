/*

Author : Manas Rawat
Date : 01/08/2023
Problem : DFS of graph
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
Video Solution : https://youtu.be/YZnpFaJ9Ad0

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> vis(V, 0);
        
        function<void(int)> dfs = [&](int node) {
            vis[node] = 1;
            ans.push_back(node);
            
            for(auto child : adj[node]){
                if(!vis[child])
                    dfs(child);
            }
        };
        
        dfs(0);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
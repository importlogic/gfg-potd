/*

Author : Manas Rawat
Date : 05/09/2023
Problem : Print adjacency list
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1
Video Solution : https://youtu.be/KRu_YsnDQc0

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        vector<vector<int>> g(V);
        
        for(auto i : edges){
            g[i.first].push_back(i.second);
            g[i.second].push_back(i.first);
        }
        
        return g;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<pair<int,int>>edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u,v});
        }
        Solution obj;
        vector<vector<int>> adj = obj.printGraph(V, edges);
        for(int i=0;i<V;i++)
        {
            sort(adj[i].begin(),adj[i].end());
            for(auto it:adj[i])
                cout<<it<<" ";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
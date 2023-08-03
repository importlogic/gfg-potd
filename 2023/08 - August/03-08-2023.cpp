/*

Author : Manas Rawat
Date : 03/08/2023
Problem : Shortest path in Directed Acyclic Graph
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
Video Solution : https://youtu.be/ruj359E4Ee0

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<int> d(N, 1e9);
        d[0] = 0;
        
        vector<vector<pair<int,int>>> g(N);
        
        for(int i = 0; i < M; i++){
            g[edges[i][0]].emplace_back(edges[i][1], edges[i][2]);
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});
        
        while(!pq.empty()){
            int cd, node;
            tie(cd, node) = pq.top();
            
            pq.pop();
            
            for(auto next : g[node]){
                int w, child;
                tie(child, w) = next;
                
                if(d[child] > d[node] + w){
                    d[child] = d[node] + w;
                    pq.push({d[child], child});
                }
            }
        }
        
        for(int i = 0; i < N; i++){
            if(d[i] == 1e9)
                d[i] = -1;
        }
        
        return d;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
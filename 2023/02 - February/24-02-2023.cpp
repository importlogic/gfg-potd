/*

Author : Manas Rawat
Date : 24/02/2023
Problem : Shortest Path Using Atmost One Curved Edge
Difficulty : Hard
Problem Link : https://practice.geeksforgeeks.org/problems/e7d81a082cda6bd1e959d943197aa3bc21b88bdb/1
Video Solution : https://youtu.be/AkNCZVLbWRM

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

vector<int> helper(int src, int dest, vector<vector<pair<int,int>>> &graph, int n){
    vector<int> ans(n + 10, 1e9);
    ans[src] = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    pair<int, int> srcitem = {0, src};
    
    pq.push(srcitem);
    
    while(!pq.empty()){
        int node, d;
        tie(d, node) = pq.top();
        
        pq.pop();
        
        for(auto nextitem : graph[node]){
            int child, dx;
            tie(child, dx) = nextitem;
            
            if(d + dx < ans[child]){
                ans[child] = d + dx;
                
                pair<int,int> newitem = {ans[child], child};
                
                pq.push(newitem);
            }
        }
    }
    
    return ans;
}

class Solution {
  public:
    int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges) {
       vector<vector<pair<int,int>>> graph(n + 10);
        
        for(int i = 0; i < m; i++){
            pair<int,int> newitem = {edges[i][1], edges[i][2]};
            
            graph[edges[i][0]].emplace_back(newitem);
            
            pair<int,int> newitem1 = {edges[i][0], edges[i][2]};
            
            graph[edges[i][1]].emplace_back(newitem1);
        }
        
        vector<int> da = helper(a, b, graph, n);
        vector<int> db = helper(b, a, graph, n);
        
        int ans = da[b];  // case 1
        
        for(int i = 0; i < m; i++){
            ans = min(ans, da[edges[i][0]] + edges[i][3] + db[edges[i][1]]);
            ans = min(ans, db[edges[i][0]] + edges[i][3] + da[edges[i][1]]);
        }
        
        return ((ans == 1e9) ? -1 : ans);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,a,b;
        cin>>n>>m;
        cin>>a>>b;
        
        vector<vector<int>> edges;
        
        for(int i=0; i<m; i++)
        {
            int u,v,x,y;
            cin>>u>>v>>x>>y;
            edges.push_back({u,v,x,y});
        }

        Solution ob;
        cout << ob.shortestPath(n,m,a,b,edges) << endl;
    }
    return 0;
}
// } Driver Code Ends
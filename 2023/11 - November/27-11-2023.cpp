/*

Author : Manas Rawat
Date : 27/11/2023
Problem : Detect Cycle using DSU
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/detect-cycle-using-dsu/1
Video Solution : https://youtu.be/5qdeYP9zjdI

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    vector<int> dsu(V, -1);
	    
	    vector<set<int>> g(V);
	    
	    for(int i = 0; i < V; i++){
	        for(auto x : adj[i])
	            g[i].insert(x);
	    }
	    
	    function<int(int)> find = [&](int p) -> int {
	        if(dsu[p] < 0) return p;
	        return dsu[p] = find(dsu[p]);
	    };
	    
	    auto merge = [&](int x, int y) {
	        if(dsu[x] > dsu[y])
	            swap(x, y);
	            
	        dsu[x] += dsu[y];
	        dsu[y] = x;
	    };
	    
	    vector<bool> vis(V, 0);
	    
	    function<bool(int, int)> dfs = [&](int node, int par) -> bool {
	        bool ans = 0;
	        vis[node] = 1;
	        
	        for(auto child : g[node]){
	            if(child != par){
	                int x = find(node);
	                int y = find(child);
	                
	                if(x == y)
	                    return 1;
	                
	                merge(x, y);    
	                   
	                ans = ans or dfs(child, node);
	            }
	        }
	        
	        return ans;
	    };
	    
	    bool ans = 0;
	    
	    for(int i = 0; i < V; i++){
	        if(!vis[i]){
	            ans = ans or dfs(i, -1);
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends
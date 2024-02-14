/*

Author : Manas Rawat
Date : 14/02/2024
Problem : Find all Critical Connections in the Graph
Difficulty : Hard
Problem Link : https://www.geeksforgeeks.org/problems/critical-connections/1
Video Solution : https://youtu.be/qEcomDglbN8

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
	vector<vector<int>>criticalConnections(int v, vector<int> adj[]){
	    vector<bool> vis(v, 0);
	    vector<int> tin(v, 0), low(v, 0);
	    int timer = 0;
	    
	    vector<vector<int>> ans;
	    
	    function<void(int, int)> dfs = [&](int node, int parent) {
	        vis[node] = 1;
	        tin[node] = low[node] = timer++;
	        
	        for(auto child : adj[node]){
	            if(child == parent) continue;
	            
	            if(vis[child])
	                low[node] = min(low[node], tin[child]); // this is actually an ancestor
	            else{
	                dfs(child, node);
	                
    	            low[node] = min(low[node], low[child]);
    	            
                    if(low[child] > tin[node])
                        ans.push_back({min(node, child), max(node, child)});
	            }
	        }
	    };
	    
	    for(int i = 0; i < v; i++){
	        if(!vis[i])
	            dfs(i, -1);
	    }
	    
	    sort(ans.begin(), ans.end());
	    
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
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends
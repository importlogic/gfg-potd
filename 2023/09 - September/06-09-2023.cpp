/*

Author : Manas Rawat
Date : 06/09/2023
Problem : Mother Vertex
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/mother-vertex/1
Video Solution : https://youtu.be/sk46MJ_h8Sk

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<int> order;
	    vector<bool> vis(V, 0);
	    
	    function<void(int)> dfs1 = [&](int node) {
	        vis[node] = 1;
	        
	        for(auto child : adj[node])
	            if(!vis[child])
	                dfs1(child);
	                
	        order.push_back(node);
	    };
	    
	    for(int i = 0; i < V; i++){
	        if(!vis[i])
	            dfs1(i);
	    }
	    
	    fill(vis.begin(), vis.end(), 0);
	    
	    int rem = V;
	    
	    function<void(int)> dfs2 = [&](int node) {
	        vis[node] = 1;
	        --rem;
	        
	        for(auto child : adj[node])
	            if(!vis[child])
	                dfs2(child);
	    };
	    
	    dfs2(order.back());
	    
	    return (rem == 0) ? order.back() : -1;
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
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
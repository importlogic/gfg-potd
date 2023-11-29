/*

Author : Manas Rawat
Date : 29/11/2023
Problem : Euler circuit and Path
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/euler-circuit-and-path/1
Video Solution : NA

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isEulerCircuit(int V, vector<int>adj[]){
	    vector<bool> vis(V, 0);
	    int left = V;
	    
	    int ans = 0;
	    
	    function<void(int)> dfs = [&](int node) {
	        vis[node] = 1;
	        --left;
	        
	        for(auto child : adj[node]){
	            if(!vis[child]){
	                dfs(child);
	            }
	        }
	    };
	    
	    dfs(0);
	    
	    int odd = 0;
	    
	    for(int i = 0; i < V; i++){
	        if(!adj[i].size())
	            --left;
	    }
	    
	    for(int i = 0; i < V; i++){
	        if(adj[i].size() & 1){
	            ++odd;
	        }
	    }
	    
	    if(left or odd > 2)
	        return 0;
	    else if(odd)
	        return 1;
	    else 
	        return 2;
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
		int ans = obj.isEulerCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends
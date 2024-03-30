/*

Author : Manas Rawat 
Date : 29/03/2024
Problem : Euler Circuit in an Undirected Graph
Difficulty : Medium 
Problem Link : https://www.geeksforgeeks.org/problems/euler-circuit-in-a-directed-graph/1
Video Solution : NA

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isEularCircuitExist(int v, vector<int>adj[]){
        for(int i=0;i<v;i++){
            if(adj[i].size()%2==1)
                return 0;
        }
        
        return 1;
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
		bool ans = obj.isEularCircuitExist(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends

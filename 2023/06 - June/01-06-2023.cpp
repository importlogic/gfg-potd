/*

Author : Manas Rawat
Date : 01/06/2023
Problem : Topological Sorting
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/topological-sort/1
Video Solution : https://youtu.be/zmXhYUDwmSc

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> in(V, 0);
	    
	    for(int i = 0; i < V; i++){
	        for(auto j : adj[i])
	            ++in[j];
	    }
	    
	    queue<int> q;
	    vector<int> order;
	    
	    for(int i = 0; i < V; i++){
	        if(in[i] == 0){
	            q.push(i);
	            order.push_back(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        
	        for(auto child : adj[node]){
	            --in[child];
	            if(in[child] == 0){
	                q.push(child);
	                order.push_back(child);
	            }
	        }
	    }
	    
	    return order;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
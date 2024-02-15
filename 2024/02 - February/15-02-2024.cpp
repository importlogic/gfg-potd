/*

Author : Manas Rawat
Date : 15/02/2024
Problem : Count all Possible Path
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/castle-run3644/1
Video Solution : https://youtu.be/KpRhZhq8Qw8

*/


//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int isPossible(vector<vector<int>>paths){
	    int n = paths.size();
	    vector<int> in(n, 0), vis(n, 0);
	    vector<vector<int>> g(n);
	    
	    
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < n; j++){
	            if(paths[i][j]){
	                g[i].push_back(j);
	                ++in[j];
	            }
	        }
	    }
	    
	    int odd = 0;
	    int cc = 0;
	    
	    function<void(int)> dfs = [&](int node) {
	        vis[node] = 1;
	        odd = odd or (in[node] & 1);
	        ++cc;
	        
	        for(auto child : g[node]) {
	            if(!vis[child])
	                dfs(child);
	        }
	    };
	    
	    dfs(0);
	    
	    return cc == n and !odd;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>paths(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> paths[i][j];
		}
		Solution obj;
		int ans = obj.isPossible(paths);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
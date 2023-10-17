/*

Author : Manas Rawat
Date : 17/10/2023
Problem : Transitive closure of a Graph
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/transitive-closure-of-a-graph0930/1
Video Solution : NA

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:
    vector<vector<int>> transitiveClosure(int n, vector<vector<int>> graph)
    {
        vector<vector<int>> d = graph;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!d[i][j])
                    d[i][j] = 1e8;
            }
            
            d[i][i] = 1;
        }
        
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                d[i][j] = d[i][j] == 1e8 ? 0 : 1;
            }
        }
        
        return d;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends
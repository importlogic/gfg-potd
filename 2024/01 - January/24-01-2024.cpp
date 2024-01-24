/*

Author : Manas Rawat
Date : 24/01/2024
Problem : Is it a tree ?
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/is-it-a-tree/1
Video Solution : https://youtu.be/0dTnXnX34CY

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
    int isTree(int n, int m, vector<vector<int>> &edge) {
        if(m != n - 1)
            return 0;
            
        vector<int> vis(n, 0);
        vector<vector<int>> g(n);
        
        for(int i = 0; i < m; i++){
            g[edge[i][0]].push_back(edge[i][1]);
            g[edge[i][1]].push_back(edge[i][0]);
        }
        
        function<bool(int, int)> dfs = [&](int node, int parent) -> bool {
            bool ans = 1;
            vis[node] = 1;
            
            for(auto child : g[node]){
                if(!vis[child])
                    ans = ans and dfs(child, node);
                else if(child != parent)
                    return 0;
            }
            
            return ans;
        };
        
        bool ans = 1;
        int cc = 0;
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                ans = ans and dfs(i, -1);
                ++cc;   
            }
        }
        
        return ans and cc == 1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
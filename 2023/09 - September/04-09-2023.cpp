/*

Author : Manas Rawat
Date : 04/09/2023
Problem : Replace O's with X's
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1
Video Solution : https://youtu.be/MtkR37cUNWI

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
                  // L, R, U, D
                  
        vector<vector<bool>> change(n, vector<bool> (m, 1)), vis(n, vector<bool> (m, 0));
        
        auto valid = [&](int x, int y) -> bool {
            if(x < 0 or x >= n or y < 0 or y >= m)
                return 0;
                
            if(vis[x][y])   
                return 0;
                
            return mat[x][y] == 'O';
        };
        
        function<void(int, int)> dfs = [&](int x, int y) {
            vis[x][y] = 1;
            change[x][y] = 0;
                
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(valid(nx, ny)){
                    dfs(nx, ny);
                }
            }
        };
        
        for(int i = 0; i < n; i++){
            if(valid(i, 0))
                dfs(i, 0);
            if(valid(i, m - 1))
                dfs(i, m - 1);
        }
        
        for(int i = 0; i < m; i++){
            if(valid(0, i))
                dfs(0, i);
            if(valid(n - 1, i))
                dfs(n - 1, i);
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                if(change[i][j])
                    mat[i][j] = 'X';
        }
        
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
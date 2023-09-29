/*

Author : Manas Rawat
Date : 29/09/2023
Problem : Number Of Enclaves
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/number-of-enclaves/1
Video Solution : NA

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans += grid[i][j] == 1;
            }
        }
        
        auto valid = [&](int x, int y) -> bool {
            if(x < 0 or x >= n or y < 0 or y >= m)
                return 0;
            
            if(vis[x][y])
                return 0;
                
            return grid[x][y];
        };
        
        function<void(int, int)> dfs = [&](int x, int y) {
            --ans;
            vis[x][y] = 1;
            
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(valid(nx, ny))
                    dfs(nx, ny);
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
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends
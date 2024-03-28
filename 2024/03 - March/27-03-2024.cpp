/*

Author : Manas Rawat 
Date : 27/03/2024
Problem : Find shortest safe route in a matrix
Difficulty : Medium 
Problem Link : https://www.geeksforgeeks.org/problems/find-shortest-safe-route-in-a-matrix/1
Video Solution : NA

*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    bool vis[1001][1001];
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    
    bool isval(int& i, int& j, int& m, int& n){
        if(i>=0 && i<m && j>=0 && j<n)return 1;
        return 0;
    }
    
    int findShortestPath(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        
       memset(vis,0,sizeof(vis));
       queue<pair<pair<int,int>,int>> q;
       
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               if(mat[i][j] == 0){
                   for(int k=0;k<4;k++){
                       int x = i + dx[k];
                       int y = j + dy[k];
                       if(isval(x,y,m,n))mat[x][y] = -1;
                   }
               }
           }
       }
       
       int ans = INT_MAX;
       for(int i=0;i<m;i++){
           if(mat[i][0] == 1)q.push({{i,0},1});
       }
       
       while(!q.empty()){
           auto cur = q.front();
           q.pop();
           int x = cur.first.first;
           int y = cur.first.second;
           int dis = cur.second;
           
           vis[x][y] = 1;
           
           if(y == n-1){
               ans = min(ans,dis);
               continue;
           }
           
           for(int k=0;k<4;k++){
               int nx = x + dx[k];
               int ny = y + dy[k];
               if(isval(nx,ny,m,n) && mat[nx][ny] == 1 && vis[nx][ny] == 0){
                   q.push({{nx,ny},dis+1});
               }
           }
       }
       
       return (ans != INT_MAX)?ans:-1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends

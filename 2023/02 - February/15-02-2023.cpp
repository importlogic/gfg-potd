/*

Author : Manas Rawat
Date : 15/02/2023
Problem : Geeks Island
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/234ca3b438298fb04befd5abe7fbd98c006d4884/1
Video Solution : https://youtu.be/YA9cn5FU-_U

*/


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int dx[] = { -1 , 1 ,  0  , 0};
int dy[] = { 0  , 0 , -1  , 1};

//         { U  , D ,  L  , R}

int n, m;

bool valid(int xx, int yy, int x, int y, vector<vector<int>> &mat){
    if(xx < 0 or xx > n - 1 or yy < 0 or yy > m - 1) return 0;
    
    if(mat[xx][yy] > mat[x][y]) return 0;
    
    return 1;
}

void dfs(int x, int y, vector<vector<int>> &mat, vector<vector<int>> &dp, vector<vector<bool>> &vis){
    vis[x][y] = 1;
    
    if(x == 0 or y == 0) dp[x][y] |= 1;
    if(x == n - 1 or y == m - 1) dp[x][y] |= 2;
    
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        
        if(valid(xx, yy, x, y, mat)){
            if(!vis[xx][yy])
                dfs(xx, yy, mat, dp, vis);
            
            dp[x][y] |= dp[xx][yy];
        }
    }
}

class Solution{   
public:
    int water_flow(vector<vector<int>> &mat,int N,int M){
        n = N;
        m = M;
        
        vector<vector<int>> dp(n, vector<int> (m, 0));
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                if(!vis[i][j])
                    dfs(i, j, mat, dp, vis);
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                ans += dp[i][j] == 3;
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends
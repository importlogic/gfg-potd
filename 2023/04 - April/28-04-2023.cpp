/*

Author : Manas Rawat
Date : 28/04/2023
Problem : Geek's Village and Wells
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/5a1277ffc1ec1d3a63d1a5d6b3920dd3d1294261/1
Video Solution : https://youtu.be/S0T_X4de-h8

*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int dx[] = { -1 , 1 ,  0  , 0 , -1  , -1  ,  1  , 1  };
int dy[] = { 0  , 0 , -1  , 1 , -1  ,  1  , -1  , 1  };
//         { U  , D ,  L  , R , UL  , UR  , DL  , DR }

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        queue<pair<int,int>> q;
        vector<vector<int>> ans(n, vector<int>(m, 1e9));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(c[i][j] == 'W')
                    q.push({i, j}), ans[i][j] = 0;
            }
        }      
        
        auto valid = [&](int x, int y) -> bool {
            if(x < 0 or x >= n or y < 0 or y >= m)
                return 0;
                
            if(c[x][y] == 'N')
                return 0;
                
            return 1;
        };
        
        while(!q.empty()){
            int x, y;
            tie(x, y) = q.front();
            
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(valid(nx, ny)){
                    if(ans[nx][ny] > ans[x][y] + 2){
                        ans[nx][ny] = ans[x][y] + 2;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(c[i][j] == 'N' or c[i][j] == 'W' or c[i][j] == '.')
                    ans[i][j] = 0;
                    
                ans[i][j] = (ans[i][j] == 1e9) ? -1 : ans[i][j];
            }
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
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends
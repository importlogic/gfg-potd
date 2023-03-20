/*

Author : Manas Rawat
Date : 20/03/2023
Problem : Shortest XY distance in Grid
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/7366ce450d84b55391fc787a681c4d60de359e72/1
Video Solution : https://youtu.be/SWwWL4D6FhQ

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int dx[] = { -1 , 1 ,  0  , 0 , -1  , -1  ,  1  , 1  };
int dy[] = { 0  , 0 , -1  , 1 , -1  ,  1  , -1  , 1  };

//         { U  , D ,  L  , R , UL  , UR  , DL  , DR }


bool valid(int x, int y, int n, int m){
    if(x < 0 or x >= n or y < 0 or y >= m) return 0;
    return 1;
}

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> &grid, int N, int M) {
        int dist[N][M];
        bool vis[N][M];
        
        queue<pair<int,int>> q;
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(grid[i][j] == 'X'){
                    q.push({i, j});
                    dist[i][j] = 0;
                    vis[i][j] = 1;
                }
                else{
                    dist[i][j] = 1e9;
                    vis[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            int x, y;
            tie(x, y) = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(valid(nx, ny, N, M) and !vis[nx][ny]){
                    dist[nx][ny] = 1 + dist[x][y];
                    
                    vis[nx][ny] = 1;
                    
                    if(grid[nx][ny] == 'Y')
                        return dist[nx][ny];
                        
                    q.push({nx, ny});
                }
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends
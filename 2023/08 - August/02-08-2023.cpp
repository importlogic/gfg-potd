/*

Author : Manas Rawat
Date : 02/08/2023
Problem : Shortest Source to Destination Path
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1
Video Solution : https://youtu.be/s8iJaW9ONDc

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if(A[0][0] == 0)
            return -1;
            
        vector<vector<int>> d(N, vector<int> (M, 500));
        d[0][0] = 0;
        
        queue<pair<int,int>> q;
        q.push({0, 0});
        
        
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        while(!q.empty()){
            int x, y;
            tie(x, y) = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                auto valid = [&]() -> bool {
                    if(nx < 0 or nx >= N or ny < 0 or ny >= M)
                        return 0;
                    
                    return A[nx][ny] == 1;
                };
                
                if(valid() and d[nx][ny] > d[x][y] + 1){
                    d[nx][ny] = d[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        return d[X][Y] == 500 ? -1 : d[X][Y];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends
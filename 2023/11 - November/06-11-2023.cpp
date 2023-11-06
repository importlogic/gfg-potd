/*

Author : Manas Rawat
Date : 06/11/2023
Problem : Letters Collection
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/c-letters-collection4552/1
Video Solution : https://youtu.be/OopdJd91Y0E

*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

int dx[] = { -1 , 1 , 0 , 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

class Solution {
public:
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[]) {
        vector<int> ans(q);
        vector<vector<bool> > vis(n, vector<bool>(m, false));
        
        for (int i = 0; i < q; i++) {
            int cx = queries[i][1];
            int cy = queries[i][2];
            int mode = queries[i][0];
            vector<pair<int, int>> one, two;
            
            vis[cx][cy] = true;
            int sum = 0;
            
            auto valid = [&](int x, int y) {
                return x >= 0 && x < n && y >= 0 && y < m;
            };
            
            for (int d1 = 0; d1 < 8; d1++) {
                int x1 = cx + dx[d1];
                int y1 = cy + dy[d1];
                
                if (valid(x1, y1)) {
                    if (mode == 1) {
                        sum += mat[x1][y1];
                    } else {
                        vis[x1][y1] = true;
                        one.emplace_back(x1, y1);
                    }
                }
            }
            
            if (mode == 2) {
                for (auto co : one) {
                    int x = co.first;
                    int y = co.second;
                    
                    for (int d1 = 0; d1 < 8; d1++) {
                        int x1 = x + dx[d1];
                        int y1 = y + dy[d1];
                        
                        if (valid(x1, y1) && !vis[x1][y1]) {
                            sum += mat[x1][y1];
                            vis[x1][y1] = true;
                            two.emplace_back(x1, y1);
                        }
                    }
                }
            }
            
            ans[i] = sum;
            
            for (auto co : one)
                vis[co.first][co.second] = false;
            for (auto co : two)
                vis[co.first][co.second] = false;
            vis[cx][cy] = false;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, q, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>q;
        vector<int> queries[q];
        for(int k = 0;k < q;k++){
            cin>>ty>>i>>j;
            queries[k].push_back(ty);
            queries[k].push_back(i);
            queries[k].push_back(j);
        }
        
        Solution ob;
        vector<int> ans = ob.matrixSum(n, m, mat, q, queries);
        for(int u: ans)
            cout<<u<<"\n";
    }
    return 0;
}
// } Driver Code Ends

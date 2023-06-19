/*

Author : Manas Rawat
Date : 30/05/2023
Problem : Word Search
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/word-search/1
Video Solution : https://youtu.be/X9PU5BTxwXk

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        
        int dx[] = { -1 , 1 ,  0  , 0};
        int dy[] = { 0  , 0 , -1  , 1};
        
        auto valid = [&](int x, int y, int p) -> bool {
            if(x < 0 or x >= n or y < 0 or y >= m)
                return 0;
            
            if(vis[x][y])
                return 0;
                
            return board[x][y] == word[p];
        };
        
        function<bool(int, int, int)> dfs = [&](int x, int y, int p) -> bool {
            if(p == word.size() - 1)
                return 1;
                
            vis[x][y] = 1;
            
            bool ok = 0;
                
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(valid(nx, ny, p + 1))
                    ok = ok or dfs(nx, ny, p + 1);
            }
            
            vis[x][y] = 0;
            return ok;
        };
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(valid(i, j, 0) and dfs(i, j, 0))
                    return 1;
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends
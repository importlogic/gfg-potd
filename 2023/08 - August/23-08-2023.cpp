/*

Author : Manas Rawat
Date : 23/08/2023
Problem : Find the string in grid
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1
Video Solution : https://youtu.be/YOnbzPRfwF0

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    int dx[] = { -1 , 1 ,  0  , 0 , -1  , -1  ,  1  , 1  };
        int dy[] = { 0  , 0 , -1  , 1 , -1  ,  1  , -1  , 1  };
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> ans;
        
        auto valid = [&](int x, int y, int p) -> bool {
            if(x < 0 or x >= n or y < 0 or y >= m)
                return 0;
            
            return grid[x][y] == word[p];
        };
        
        function<bool(int, int, int, int)> helper = [&](int x, int y, int dir, int p) -> bool {
            if(p == word.size() - 1)
                return 1;
                
            if(valid(x + dx[dir], y + dy[dir], p + 1))
                return helper(x + dx[dir], y + dy[dir], dir, p + 1);
                
            return 0;
        };
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < 8; k++){
                    if(valid(i, j, 0) and helper(i, j, k, 0)){
                        vector<int> t = {i, j};
                        ans.push_back(t);
                        break;
                    }
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends
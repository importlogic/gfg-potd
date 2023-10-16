/*

Author : Manas Rawat
Date : 16/10/2023
Problem : Making A Large Island
Difficulty : Hard
Problem Link : https://practice.geeksforgeeks.org/problems/making-a-large-island/1
Video Solution : NA

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        int n = grid.size();
        
        vector<int> dsu(n * n, -1);
       
        auto index = [&](int x, int y) -> int {
            return x * n + y;
        }; 
        
        function<int(int)> find = [&](int p) -> int {
            if(dsu[p] < 0) return p;
            
            return dsu[p] = find(dsu[p]);
        };
        
        auto merge = [&](int a, int b) {
            if(dsu[a] > dsu[b])
                swap(a, b);
                
            dsu[a] += dsu[b];
            dsu[b] = a;
        };
        
        auto valid = [&](int x, int y) -> bool {
            if(x < 0 or y < 0 or x >= n or y >= n)
                return 0;
                
            return grid[x][y];
        };
        
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!grid[i][j])
                    continue;
                    
                for(int d = 0; d < 4; d++){
                    int x = i + dx[d];
                    int y = j + dy[d];
                    
                    if(valid(x, y)){
                        int a = find(index(i, j));
                        int b = find(index(x, y));
                        
                        if(a != b){
                            merge(a, b);
                        }
                    }
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    ans = max(ans, abs(dsu[find(index(i, j))]));
                }
                else{
                    set<int> p;
                    int cur = 1;
                    
                    for(int d = 0; d < 4; d++){
                        int x = i + dx[d];
                        int y = j + dy[d];
                        
                        if(valid(x, y)){
                            p.insert(find(index(x, y)));
                        }
                    }
                    
                    for(auto i : p)
                        cur += abs(dsu[i]);
                        
                    ans = max(ans, cur);
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends
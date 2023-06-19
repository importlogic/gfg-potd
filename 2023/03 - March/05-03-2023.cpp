/*

Author : Manas Rawat
Date : 05/03/2023
Problem : Avoid Explosion
Difficulty : Hard
Problem Link : https://practice.geeksforgeeks.org/problems/d3fd6eb758469ab11e1a812220740d1f9819be70/1
Video Solution : https://youtu.be/pRDQTJYERn4

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int ds[1020];

int find(int x){
    if(ds[x] < 0)
        return x;
    
    return ds[x] = find(ds[x]);
}

void merge(int a, int b){
    if(a == b)
        return;
    
    if(ds[a] > ds[b])
        swap(a, b);
        
    ds[a] += ds[b];
    ds[b] = a;
}

class Solution {
  public:
    vector<string> avoidExplosion(vector<vector<int>> mix, int n, vector<vector<int>> danger, int m) {
        vector<string> ans;
        
        for(int i = 0; i < n + 1; i++)
            ds[i] = -1;
            
        for(int i = 0; i < n; i++){
            int a = find(mix[i][0]);
            int b = find(mix[i][1]);
            
            if(a > b)
                swap(a, b);
            
            bool ok = 1;
            
            for(int j = 0; j < m; j++){
                int x = find(danger[j][0]);
                int y = find(danger[j][1]);
                
                if(x > y)
                    swap(x, y);
                
                if(a == x and b == y){
                    ok = 0;
                    break;
                }
            }
            
            if(ok){
                merge(a, b);
                ans.push_back("Yes");
            }
            else{
                ans.push_back("No");
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mix(n, vector<int>(2));
        vector<vector<int>> danger(m, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> mix[i][0] >> mix[i][1];
        }

        for (int i = 0; i < m; i++) {
            cin >> danger[i][0] >> danger[i][1];
        }

        auto ans = sol.avoidExplosion(mix, n, danger, m);
        for (auto &val : ans) cout << val << " ";
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends
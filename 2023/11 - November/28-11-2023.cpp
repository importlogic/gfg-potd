/*

Author : Manas Rawat
Date : 28/11/2023
Problem : Sum of dependencies in a graph
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/sum-of-dependencies-in-a-graph5311/1
Video Solution : https://youtu.be/5WWG_QlwTbU

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int sumOfDependencies(vector<int> adj[], int V) {
        int ans = 0;
        
        for(int i = 0; i < V; i++){
            ans += adj[i].size();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<int> v[N];
        for (int i = 0; i < M; i++) {
            cin >> x >> y;
            v[x].push_back(y);
        }
        Solution ob;
        cout << ob.sumOfDependencies(v, N) << "\n";
    }
}
// } Driver Code Ends
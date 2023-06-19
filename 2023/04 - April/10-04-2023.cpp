/*

Author : Manas Rawat
Date : 10/04/2023
Problem : Maximum Intersecting Lines
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/63c232252d445a377e01cd91adfd7d1060580038/1
Video Solution : https://youtu.be/sZMeKXdbxVk

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        map<int,int> start, end;
        
        for(auto item : lines){
            start[item[0]]++;
            end[item[1]]++;
        }
        
        int startSum, endSum, ans;
        startSum = endSum = ans = 0;
        
        for(auto &e : end){
            e.second += endSum;
            endSum = e.second;
        }
        
        for(auto &e : start){
            e.second += startSum;
            startSum = e.second;
            
            int remove = 0;
            auto ptr = end.lower_bound(e.first);
            if(ptr != end.begin())
                --ptr, remove = (*ptr).second;
                
            ans = max(ans, e.second - remove);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends
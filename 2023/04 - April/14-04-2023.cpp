/*

Author : Manas Rawat
Date : 14/04/2023
Problem : Remove the balls
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/546ea68f97be7283a04ddcc8057e09b46a686471/1
Video Solution : https://youtu.be/e_wZ9dnnmf4

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int N, vector<int> color, vector<int> radius) {
        stack<pair<int,int>> current;
        int index = 0;
        
        while(index < N){
            while(index < N and current.size() and current.top() == make_pair(color[index], radius[index]))
                current.pop(), ++index;
            
            if(index < N){
                current.push({color[index], radius[index]});
                ++index;
            }
        }
        
        return current.size();
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends
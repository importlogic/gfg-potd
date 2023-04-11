/*

Author : Manas Rawat
Date : 11/04/2023
Problem : Maximum Length
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/84963d7b5b84aa24f7807d86e672d0f97f41a4b5/1
Video Solution : https://youtu.be/9eovpNNKwH0

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int a, int b, int c) {
        vector<int> v = {a, b, c};
        sort(v.begin(), v.end());
        
        int nax = max({a, b, c});
        int sum = a + b + c - nax;
        
        return (nax <= sum * 2) ? a + b + c : -1;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        Solution ob;
        int ans = ob.solve(a, b, c);
     

        cout <<  ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
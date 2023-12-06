/*

Author : Manas Rawat
Date : 06/12/2023
Problem : How Many X's?
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/how-many-xs4514/1
Video Solution : https://youtu.be/PJ0KCFmrrBo

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countX(int L, int R, int X) {
        int ans = 0;
        
        for(int i = L + 1; i < R; i++){
            int cur = i;
            
            while(cur){
                ans += (cur % 10) == X;
                cur /= 10;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R, X;
        cin >> L >> R >> X;
        Solution ob;
        int ans = ob.countX(L, R, X);
        cout << ans << "\n";
    }
}

// } Driver Code Ends
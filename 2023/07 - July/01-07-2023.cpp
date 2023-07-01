/*

Author : Manas Rawat
Date : 01/07/2023
Problem : Number of 1 Bits
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/set-bits0143/1
Video Solution : https://youtu.be/ql5dId1qQYg

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int setBits(int N) {
        int ans = 0;
        
        while(N){
            ++ans;
            N &= (N - 1);
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

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

// } Driver Code Ends
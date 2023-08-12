/*

Author : Manas Rawat
Date : 13/08/2023
Problem : Nth Fibonacci Number
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/nth-fibonacci-number1335/1
Video Solution : https://youtu.be/twu9oyOaqRg

*/


//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        int x, y;
        x = y = 1;
        
        const int mod = 1e9 + 7;
            
        for(int i = 3; i < n + 1; i++){
            x = (x + y) % mod;
            swap(x, y);
        }
        
        return y;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
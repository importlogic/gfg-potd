/*

Author : Manas Rawat
Date : 06/03/2023
Problem : Geek hates too many 1s
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/07e45fe40846bc670ad2507d2c649304699768b9/1
Video Solution : https://youtu.be/GYNKlXvHNx4

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) {
        vector<int> number(32);
        
        for(int i = 0; i < 32; i++)
            number[i] = (n >> i) & 1;
        
        int ans = 0;
        
        for(int i = 31; i > -1; i--){
            ans += number[i] << i;
            
            if(i > 1)
                if(number[i] & number[i - 1] & number[i - 2])
                    number[i - 2] = 0;
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

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends
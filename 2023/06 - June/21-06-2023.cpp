/*

Author : Manas Rawat
Date : 21/06/2023
Problem : Reverse Coding
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/reverse-coding2452/1
Video Solution : https://youtu.be/88KQl7K1giM

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int sumOfNaturals(int n) {
        const int mod = 1e9 + 7;
        long long ans = (n * (n + 1LL)) % mod;
        ans = (ans * 500000004LL) % mod;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.sumOfNaturals(n) << endl;
    }
    return 0;
}
// } Driver Code Ends
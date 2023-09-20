/*

Author : Manas Rawat
Date : 20/09/2023
Problem : Rotate Bits
Difficulty : Basic
Problem Link : https://practice.geeksforgeeks.org/problems/rotate-bits4524/1
Video Solution : NA

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            vector<int> ans(2, 0);
            d %= 16;
            ans[0] = (n << d) | (n >> (16 - d));
            ans[1] = (n >> d) | (n << (16 - d));
            
            ans[0] &= (1 << 16) - 1;
            ans[1] &= (1 << 16) - 1;
            
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
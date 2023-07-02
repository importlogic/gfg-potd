/*

Author : Manas Rawat
Date : 02/07/2023
Problem : Copy Set Bits in Range
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/copy-set-bits-in-range0623/1
Video Solution : https://youtu.be/Ns-WPiaaqg4

*/


//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        --l;
        --r;
        
        for(int i = l; i < r + 1; i++){
            int bit = (y >> i) & 1;
            x |= bit << i;
        }
        
        return x;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
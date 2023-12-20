/*

Author : Manas Rawat
Date : 20/12/2023
Problem : Modified Game of Nim
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/variation-in-nim-game4317/1
Video Solution : https://youtu.be/hvfWHPVgxPg

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findWinner(int n, int A[]){
        int val = 0;
        
        for(int i = 0; i < n; i++)
            val ^= A[i];
        
        return ((n & 1) and val > 0) ? 2 : 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i = 0;i < n;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.findWinner(n, A)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
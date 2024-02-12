/*

Author : Manas Rawat
Date : 12/02/2024
Problem : Recursive sequence
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/recursive-sequence1611/1
Video Solution : https://youtu.be/MgQ-1VTGePo

*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        const long long mod = 1e9 + 7;
        
        long long p = 1;
        long long ans = 0;
        
        for(int i = 1; i < n + 1; i++){
            long long val = 1;
            
            for(int j = 0; j < i; j++){
                val = (val * (p++)) % mod;
            }
            
            ans = (ans + val) % mod;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends
/*

Author : Manas Rawat
Date : 20/02/2023
Problem : Count Cyclic Paths
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/aa0000a5f710ce8d41366b714341eef644ec7b82/1
Video Solution : https://youtu.be/g3uS0snEFIM

*/


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

int dp[1000010][4]; // 1e6 + 10

class Solution{   
public:
    int countPaths(int N){
        const int mod = 1e9 + 7;
        
        for(int i = 0; i < 4; i++) dp[0][i] = 0;
        dp[0][0] = 1;
        
        for(int i = 1; i < N + 1; i++){
            for(int j = 0; j < 4; j++){
                int x = (j + 1) % 4;
                int y = (j - 1 + 4) % 4;
                int z = (j + 6) % 4;
                
                dp[i][j] = (dp[i - 1][x] + dp[i - 1][y]) % mod;
                dp[i][j] = (dp[i][j] + dp[i - 1][z]) % mod;
            }
        }
        
        return dp[N][0];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends
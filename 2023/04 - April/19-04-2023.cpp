/*

Author : Manas Rawat
Date : 19/04/2023
Problem : Wifi Range
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/61567fb59e9f202db5cc2ad320ffeb6d95bf72d7/1
Video Solution : https://youtu.be/rl2ACFIJGT8

*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        int current = 0;
        
        for(auto i : S){
            if(i == '1'){
                current = -X;
                continue;
            }
            
            ++current;
            
            if(current > X)
                return 0;
        }
        
        return current <= 0;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends
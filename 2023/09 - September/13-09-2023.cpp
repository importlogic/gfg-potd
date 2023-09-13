/*

Author : Manas Rawat
Date : 13/09/2023
Problem : Largest number possible
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/largest-number-possible5028/1
Video Solution : NA

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        string ans = "";
        
        if(S == 0){
            return (N == 1) ? "0" : "-1"; 
        }
        
        while(N--){
            int cur = min(9, S);
            S -= cur;
            
            ans += (char)('0' + cur);
        }
        
        return (S > 0) ? "-1" : ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
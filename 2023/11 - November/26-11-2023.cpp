/*

Author : Manas Rawat
Date : 26/11/2023
Problem : Print Pattern
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/print-pattern3549/1
Video Solution : https://youtu.be/JNh6ZIOOaL0

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void helper(int cur, int N, vector<int> &ans, int dx){
        ans.push_back(cur);
            
        if(cur <= 0)
            dx = 5;
        
        if(cur < N or dx == -5)    
            helper(cur + dx, N, ans, dx);
    }
    
    vector<int> pattern(int N){
        vector<int> ans;
        helper(N, N, ans, -5);
        
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
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
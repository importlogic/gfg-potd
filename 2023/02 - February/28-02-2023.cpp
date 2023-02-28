/*

Author : Manas Rawat
Date : 28/02/2023
Problem : Optimal Array
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/d4aeef538e6dd3280dda5f8ed7964727fdc7075f/1
Video Solution : https://youtu.be/HAefbaSoRtc

*/

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> optimalArray(int n,vector<int> &a){
        vector<int> ans(n, 0);
        
        for(int i = 1; i < n; i++){
            int x = abs(a[i] - a[i / 2]);
            
            ans[i] = ans[i - 1] + x;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution obj;
        vector<int> ans=obj.optimalArray(n,a);
        for(auto ele:ans){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
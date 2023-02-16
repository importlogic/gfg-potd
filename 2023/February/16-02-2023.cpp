/*

Author : Manas Rawat
Date : 16/02/2023
Problem : Good Stones
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/e2d156755ca4e0a9b9abf5680191d4b06e52b1a8/1
Video Solution : https://youtu.be/w9kYl8IAVkE

*/


//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

bool loopfound;

void dfs(int node, int n, vector<int> &arr, vector<bool> &vis){
    vis[node] = 1;
    
    int child = node + arr[node];
    
    if(child < n and child > -1){
        if(vis[child]){
            loopfound = 1;
        }
        else
            dfs(child, n, arr, vis);
    }
    
    if(!loopfound)
        vis[node] = 0;
}

class Solution{
public:
    int goodStones(int n,vector<int> &arr){
        vector<bool> vis(n, 0);
        
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                loopfound = 0;
                dfs(i, n, arr, vis);
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            ans += vis[i] == 0;
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
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
/*

Author : Manas Rawat
Date : 04/05/2023
Problem : Max Coins
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/111fb97b983399c0ee9f34b7bae18ac76bf6f07a/1
Video Solution : https://youtu.be/G4CZTVzovsk

*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxCoins(int n,vector<vector<int>> &ranges){
        sort(ranges.begin(), ranges.end(), [&](vector<int> &a, vector<int> &b){
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        
        vector<int> post(n);
        post[n - 1] = ranges[n - 1][2];
        
        for(int i = n - 2; i > -1; i--)
            post[i] = max(post[i + 1], ranges[i][2]);
            
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            int l = i;
            int h = n;
            
            while(l < h - 1){
                int mid = l + (h - l) / 2;
                
                if(ranges[mid][0] >= ranges[i][1])
                    h = mid;
                else
                    l = mid;
            }
            
            int cur = 0;
            if(h < n)
                cur = post[h];
                
            ans = max(ans, ranges[i][2] + cur);
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
        vector<vector<int>> a(n,vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        Solution ob;
        cout<<ob.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends
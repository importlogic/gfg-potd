/*

Author : Manas Rawat
Date : 16/06/2023
Problem : Min Time
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/95bb244da24edd6214086ff934886ccda6ed9da8/1
Video Solution : https://youtu.be/FqAj0uZjWLk

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long minTime(int n, vector<int> &locations, vector<int> &types) {
        map<int, vector<int>> mp;
        
        for(int i = 0 ; i < n; i++){
            if(mp.find(types[i]) != mp.end()){
                mp[types[i]][0] = min(mp[types[i]][0], locations[i]);
                mp[types[i]][1] = max(mp[types[i]][1], locations[i]);
            }
            else{
                mp[types[i]].push_back(locations[i]);
                mp[types[i]].push_back(locations[i]);
            }
        }
        
        vector<vector<int>> v;
        vector<int> zero = {0, 0};
        v.emplace_back(zero);
        
        for(auto i : mp){
            v.emplace_back(i.second);
        }
        
        v.emplace_back(zero);
        
        n = v.size();
        
        vector<vector<long long>> dp(n, vector<long long> (2, 0));
        
        for(int i = 1; i < n; i++){
            // taking current type minimum and last type minimum
            dp[i][0] = dp[i - 1][0] + abs(v[i - 1][1] - v[i][0]) + abs(v[i][0] - v[i][1]);
            
            // taking current type minimum and last type maximum
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + abs(v[i - 1][0] - v[i][0]) + abs(v[i][1] - v[i][0]));
            
            // taking current type maximum and last type minimum
            dp[i][1] = dp[i - 1][0] + abs(v[i][1] - v[i - 1][1]) + abs(v[i][0] - v[i][1]);
            
            // taking current type maximum and last type maximum
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + abs(v[i - 1][0] - v[i][1]) + abs(v[i][0] - v[i][1]));
        }
        
        return dp[n - 1][1];
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
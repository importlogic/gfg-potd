/*

Author : Manas Rawat
Date : 15/01/2024
Problem : Grinding Geek
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/grinding-geek/1
Video Solution : https://youtu.be/94aTAP85fMk

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int max_courses(int n, int total, vector<int> &cost)
    {
        vector<vector<int>> dp(n + 1, vector<int> (total + 1, 0));
        
        for(int i = n - 1; i > -1; i--){
            for(int j = 0; j < total + 1; j++){
                int take = 0, notake = 0;
                
                notake = dp[i + 1][j];
                
                if(cost[i] <= j){
                    int rem = j - cost[i] + (cost[i] * 9) / 10;
                    take = 1 + dp[i + 1][rem];
                }
                
                dp[i][j] = max(take, notake);
            }
        }
        
        return dp[0][total];
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends
/*

Author : Manas Rawat
Date : 01/03/2023
Problem : Update Queries
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/a6528c893d4ab645ec6e0690c7982748385099c8/1
Video Solution : https://youtu.be/HEwqQ9-i8hw

*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> updateQuery(int N,int Q,vector<vector<int>> &U)
        {
            vector<vector<int>> start(N), end(N);
            
            for(auto query : U){
                start[query[0] - 1].push_back(query[2]);
                end[query[1] - 1].push_back(query[2]);
            }
            
            vector<vector<int>> bitans(N, vector<int> (32, 0));
            
            for(int i = 0; i < N; i++){
                for(auto number : start[i]){
                    for(int j = 0; j < 32; j++)
                        bitans[i][j] += (number >> j) & 1;
                }
                
                if(i > 0){
                    for(int j = 0; j < 32; j++)
                        bitans[i][j] += bitans[i - 1][j];
                    
                    for(auto number : end[i - 1]){
                        for(int j = 0; j < 32; j++)
                            bitans[i][j] -= (number >> j) & 1;
                    }
                }
            }
            
            vector<int> ans(N);
            
            for(int i = 0; i < N; i++){
                int value = 0;
                
                for(int j = 0; j < 32; j++){
                    if(bitans[i][j] > 0)
                        value += (1 << j);
                }
                
                ans[i] = value;
            }
            
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector <vector <int>> u(q,vector <int>(3));
        for(int i=0;i<q;i++)
            cin>>u[i][0]>>u[i][1]>>u[i][2];
        Solution a;
        vector <int> ans=a.updateQuery(n,q,u);//<<endl;
        for(auto j:ans)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
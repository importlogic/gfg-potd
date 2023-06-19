/*

Author : Manas Rawat
Date : 14/03/2023
Problem : Maximum Number of coins
Difficulty : Hard
Problem Link : https://practice.geeksforgeeks.org/problems/7ae455e552dc4e07f76bbe2adc4d4207ce1ff16e/1
Video Solution : https://youtu.be/DTTPN6XivKg

*/


//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
        int maxCoins(int N, vector <int> &a)
        {
            vector<int> v(N + 2);
            v[0] = v[N + 1] = 1;
            
            for(int i = 0; i < N; i++)
                v[i + 1] = a[i];
                
            vector<vector<int>> dp(N + 2, vector<int>(N + 2));
            
            for(int i = N; i > 0; i--){
                for(int j = i; j < N + 1; j++){
                    int cost = 0;
                    for(int k = i; k < j + 1; k++){
                        int currentCost = v[k] * v[i - 1] * v[j + 1] + dp[i][k - 1] + dp[k + 1][j];
                        cost = max(cost, currentCost);
                    }
                    
                    dp[i][j] = cost;
                }
            }
            
            return dp[1][N];
        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends
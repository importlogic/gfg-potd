/*

Author : Manas Rawat
Date : 23/02/2024
Problem : Buy and Sell a Share at most twice
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/buy-and-sell-a-share-at-most-twice/1
Video Solution : NA

*/


//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        
        int maxProfit(vector<int>&price){
            int n = price.size();
            vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (3, 0)));

            for(int i = n - 1; i > -1; i--) {
                for(int j = 0; j < 2; j++){
                    for(int k = 1; k < 3; k++) {
                        dp[i][j][k] = 0;
                        
                        if(j) {
                            dp[i][j][k] = max(price[i] + dp[i + 1][0][k - 1], dp[i + 1][1][k]);       
                        }
                        else {
                            dp[i][j][k] = max(-price[i] + dp[i + 1][1][k], dp[i + 1][0][k]);
                        }
                    }
                }
            }
            
            return dp[0][0][2];
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends

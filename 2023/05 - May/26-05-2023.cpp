/*

Author : Manas Rawat
Date : 26/05/2023
Problem : Express as sum of power of natural numbers
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/express-as-sum-of-power-of-natural-numbers5647/1
Video Solution : https://youtu.be/fL6fNTxuogY

*/


//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int numOfWays(int n, int x)
    {
        const int mod = 1e9 + 7;
        
        auto expo = [](int n, int p) -> int {
            int ans = 1;
            
            while(p){
                if(p & 1){
                    ans = ans * n;
                }
                
                n = n * n;
                p >>= 1;
            }
            
            return ans;
        };
        
        vector<int> v = {0};
        
        for(int i = 1; expo(i, x) < n + 1; i++){
            v.push_back(expo(i, x));
        }
        
        int size = v.size();
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        
        for(int i = 1; i < size; i++){
            vector<int> newdp(n + 1, 0);
            
            for(int j = 0; j < n + 1; j++){
                int take, notake;
                take = notake = 0;
                
                if(j >= v[i])
                    take = dp[j - v[i]];
                notake = dp[j];
                
                newdp[j] = (take + notake) % mod;
            }
            
            dp = newdp;
        }
        
        return dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends
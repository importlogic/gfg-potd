/*

Author : Manas Rawat
Date : 28/01/2024
Problem : Geekina Hate 1s
Difficulty : Hard
Problem Link : https://www.geeksforgeeks.org/problems/geekina-hate-1s/1
Video Solution : https://youtu.be/kFpwHe9Q73Y

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long findNthNumber(long long n, long long k) {
        auto ncr = [](long long n, long long r) -> long long {
            long long ans = 1;
            
            // n! / ((n - r)! * r!)
            
            for(long long i = n; i > max(r, n - r); i--)
                ans *= i;
                
            long long den = 1;
            
            for(long long i = 1; i <= min(r, n - r); i++)
                den *= i;
                
            ans /= den;
            
            return ans;
        };
        
        vector<vector<long long>> dp(63, vector<long long> (k + 1, 0));
        
        for(int i = 0; i < 63; i++){
            for(int j = 0; j < k + 1; j++){
                for(int x = 0; x <= min(i + 1, j); x++)
                    dp[i][j] += ncr(i + 1, x);
            }
        }
        
        long long pos = 0;
        
        for(int i = 0; i < 63; i++){
            if(dp[i][k] >= n){
                pos = i;
                break;
            }
        }
        
        long long ans = 0;
        while(pos > -1 and n > 0){
            if(pos + 1 <= k){
                ans += n - 1;
                break;
            }
            
            if(pos > 0 and dp[pos - 1][k] < n){
                ans |= (1LL << pos);
                n -= dp[pos - 1][k];
                k = (k-1<0LL)?0LL:k-1;
            }
            
            --pos;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        Solution obj;
        long long res = obj.findNthNumber(n, k);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends

/*

Author : Manas Rawat
Date : 15/05/2023
Problem : Count Total Setbits
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/1132bd8ee92072cd31441858402641d6800fa6b3/1
Video Solution : https://youtu.be/ntDjZXwe02w

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long countBits(long long N) {
        long long ans = 0;
        ++N;
        
        for(long long i = 0; i < 32; i++){
            long long x = N / (1LL << (i + 1));
            x = x * (1 << i);
            ans += x;
            
            if(i < 31){
                long long y = N % (1LL << (i + 1));
                y = max(0LL, y - (1LL << i));
                ans += y;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
/*

Author : Manas Rawat
Date : 09/04/2023
Problem : Special Digits
Difficulty : Hard
Problem Link : https://practice.geeksforgeeks.org/problems/7a3e0427cbb1ea9fbfec499dc6fce377ffdf7aed/1
Video Solution : https://youtu.be/MLSIr2C5X2M

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

const int maxSize = 1e5 + 10;
long long fact[maxSize];
const int mod = 1e9 + 7;

int power(long long n, long long x){
    long long ans = 1;
    
    while(x > 0){
        if(x & 1){
            ans = (ans * n) % mod;
            --x;
        }
        else{
            n = (n * n) % mod;
            x >>= 1;
        }
    }

    
    return ans % mod;
}

bool checker(int n, int c, int d){
    string s = to_string(n);
    
    for(auto i : s){
        if(i - '0' != c and i - '0' != d)
            return 0;
    }
    
    return 1;
}

int ncr(long long n, long long r){
    
    long long ans = fact[n]; // ncr = n! / ((n - r)! * r!)
    ans = (ans * power(fact[r], mod - 2)) % mod;
    ans = (ans * power(fact[n - r], mod - 2)) % mod;

    return ans % mod;
}

class Solution {
  public:
    int bestNumbers(int N, int A, int B, int C, int D) {
        // code here
        
        fact[0] = fact[1] = 1;
        
        for(int i = 2; i < N + 5; i++)
            fact[i] = (i * fact[i - 1]) % mod;
            
        int ans = 0;
        
        for(int i = 0; i <= N; i++){
            int sum = i * A + (N - i) * B;
            if(checker(sum, C, D))
                ans = (ans + ncr(N, i)) % mod;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int A;
        scanf("%d",&A);
        
        
        int B;
        scanf("%d",&B);
        
        
        int C;
        scanf("%d",&C);
        
        
        int D;
        scanf("%d",&D);
        
        Solution obj;
        int res = obj.bestNumbers(N, A, B, C, D);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
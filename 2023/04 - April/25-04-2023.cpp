/*

Author : Manas Rawat
Date : 25/04/2023
Problem : Game Of Subsets
Difficulty : Hard
Problem Link : https://practice.geeksforgeeks.org/problems/cec5db442a5652d07dd41e37ea780345f08c9a3d/1
Video Solution : https://youtu.be/CCWU8S7cMy8

*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int dp[100010][1024];

class Solution{
public:
    int goodSubsets(vector<int> &arr, int n){
        const int mod = 1e9 + 7;
        
        map<int,int> bits = {   {2, 0},
                                {3, 1}, 
                                {5, 2},
                                {7, 3},
                                {11,4},
                                {13, 5},
                                {17, 6},
                                {19, 7},
                                {23, 8},
                                {29, 9}
                            };
                            
        
        vector<int> mask(31, 0);
        
        for(int i = 2; i < 31; i++){
            int currentMask = 0;
            bool ok = 1;
            int val = i;
            
            for(int j = 2; j * j <= val; j++){
                while(val % j == 0){
                    int pos = bits[j];
                    
                    if((currentMask >> pos) & 1){
                        ok = 0;
                        break;
                    }
                    
                    currentMask |= (1 << pos);
                    
                    val /= j;
                }
                
                if(!ok)
                    break;
            }            
            
            if(val > 1){
                int pos = bits[val];
                
                if((currentMask >> val) & 1)
                    ok = 0;
                else
                    currentMask |= (1 << pos);
            }
            
            if(!ok)
                mask[i] = 0;
            else
                mask[i] = currentMask;
        }
        
        dp[0][0] = 0;
        for(int i = 1; i < 1024; i++)
            dp[0][i] = 1;
        
            
        int count = 0;
        for(int i = 1; i < n + 1; i++){
            if(arr[i - 1] == 1)
                ++count;
                
            for(int currentMask = 0; currentMask < 1024; currentMask++){
                int val = arr[i - 1];
                
                if(val == 1){
                    dp[i][currentMask] = dp[i - 1][currentMask];
                    continue;
                }
                
                bool ok = 1;
                int finalMask;
                
                if(mask[val]){
                    if(mask[val] & currentMask)
                        ok = 0;
                    else
                        finalMask = mask[val] | currentMask;
                }
                else{
                    ok = 0;
                }
                
                if(ok){
                    int x = dp[i - 1][finalMask];
                    int y = dp[i - 1][currentMask];
                    
                    dp[i][currentMask] = (x + y) % mod;
                }
                else{
                    dp[i][currentMask] = dp[i - 1][currentMask];
                }
            }
        }
        
        auto expo = [](long long a, int n, int mod) -> long long {
            long long res = 1; 
            
            while(n){ 
                if(n & 1) {
                    res = (res * a) % mod;
                    --n;
                } 
                else {
                    a = (a * a) % mod;
                    n >>= 1;
                }
            } 
            
            return res;    
        };
        
        long long ways = expo(2, count, mod);
        
        int ans = (dp[n][0] * ways) % mod;
        
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
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution ob;
        cout<<ob.goodSubsets(a, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
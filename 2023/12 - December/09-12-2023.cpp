/*

Author : Manas Rawat
Date : 09/12/2023
Problem : Smith Number
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/smith-number4132/1
Video Solution : https://youtu.be/2qE1YZ8WeqE

*/


//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int digitSum(int n){
        int ans = 0;
        
        while(n){
            ans += n % 10;
            n /= 10;
        }
        
        return ans;
    }
    
    int smithNum(int n) {
        vector<int> sieve(n + 1, 1e9);
        
        for(int i = 2; i < n + 1; i++){
            if(sieve[i] == 1e9){
                sieve[i] = i;
                for(int j = i + i; j < n + 1; j += i)
                    sieve[j] = min(sieve[j], i);
            }
        }
        
        if(sieve[n] == n)
            return 0;
        
        int suma, sumb;
        suma = sumb = 0;
        
        sumb = digitSum(n);
        
        while(n > 1){
            suma += digitSum(sieve[n]);
            n /= sieve[n];
        }
        
        return suma == sumb;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends
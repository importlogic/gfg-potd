/*

Author : Manas Rawat
Date : 17/02/2023
Problem : Is it Fibonacci
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/202d95ecdeec659401edc63dd952b1d37b989ab8/1
Video Solution : https://youtu.be/fY2O3ap_Zxs

*/
    

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        int size = max(N, K);
        vector<long long> ans(size);
        
        long long sum = 0;
        
        for(int i = 0; i < K; i++){
            ans[i] = GeekNum[i];
            sum += GeekNum[i];
        }
        
        int i = 0;
        int j = K;
        
        for(int p = K; p < N; p++){
            ans[p] = sum;
            
            sum -= ans[i++];
            sum += ans[j++];
        }


        return ans[N - 1];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends
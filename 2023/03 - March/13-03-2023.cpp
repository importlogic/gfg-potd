/*

Author : Manas Rawat
Date : 13/03/2023
Problem : Maximum Possible Value
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/2d3fc3651507fc0c6bd1fa43861e0d1c43d4b8a1/1
Video Solution : https://youtu.be/TIRhU-aPe14

*/


//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
        long long count = 0;
        long long nin = 1e10;
        
        long long ans = 0;
        
        for(int i = 0; i < N; i++){
            ans += B[i] / 2LL * A[i] * 2LL;
            
            if(B[i] > 1){
                nin = min(nin, (long long)A[i]);
                count += B[i] / 2;
            }
        }
        
        if(count & 1)
            ans -= 2LL * nin;
            
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends
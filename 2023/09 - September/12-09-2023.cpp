/*

Author : Manas Rawat
Date : 12/09/2023
Problem : Perfect Numbers
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/perfect-numbers3207/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        if(N == 1)
            return 0;
            
        long long sum = 1;
        
        for(int i = 2; i <= sqrt(N); i++){
            if(N % i == 0){
                sum += i;
                if(i != N / i)
                    sum += N / i;
            }
        }
        
        return sum == N;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
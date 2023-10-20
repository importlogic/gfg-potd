/*

Author : Manas Rawat
Date : 20/10/2023
Problem : Form a number divisible by 3 using array digits
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/form-a-number-divisible-by-3-using-array-digits0717/1
Video Solution : NA

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isPossible(int N, int arr[]) {
        int sum = 0;
        
        for(int i = 0; i < N; i++){
            int x = arr[i];
            
            while(x){
                sum += x % 10;
                x /= 10;
            }
        }
        
        return sum % 3 == 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        cout << ob.isPossible(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
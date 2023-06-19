/*

Author : Manas Rawat
Date : 05/04/2023
Problem : Count Special Numbers
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/3d49e4cce2820a813da02d1587c2dd9c542ce769/1
Video Solution : https://youtu.be/0AtG6kDm_5k

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        int nax = *max_element(arr.begin(), arr.end());
        
        vector<int> present(nax + 10, 0);
        vector<bool> take(nax + 10, 0);
        
        for(auto i : arr)
            ++present[i];
        
        if(present[1]){
            int ans = N - 1;
            
            if(present[1] > 1)
                ++ans;
                
            return ans;
        }
        
        for(int i = 2; i <= nax; i++){
            if(present[i]){
                for(int j = i + i; j <= nax; j += i){
                    if(present[j])
                        take[j] = 1;
                }
            }
        }
        
        int ans = 0;
        
        for(int i = 2; i < nax + 10; i++){
            if(present[i] > 1)
                ans += present[i];
            else if(take[i])
                ++ans;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
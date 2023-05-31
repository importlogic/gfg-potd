/*

Author : Manas Rawat
Date : 31/05/2023
Problem : Frequency Game
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/frequency-game/1
Video Solution : https://youtu.be/LCpoflIe-B0

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        unordered_map<int,int> f;
        
        for(int i = 0; i < n; i++)
            ++f[arr[i]];
            
        int minFrequency, ans = -1;
        minFrequency = 1e6;
        
        for(auto it : f){
            if(it.second < minFrequency){
                minFrequency = it.second;
                ans = it.first;
            }
            else if(it.second == minFrequency){
                ans = max(ans, it.first);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends
/*

Author : Manas Rawat
Date : 11/05/2023
Problem : Palindrome with minimum sum
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/32dc957908c2eb8beeeaeedf81f37df20d37c308/1
Video Solution : https://youtu.be/xUSeYwqDtWE

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        int n = s.size();
        
        vector<int> v(n);
        int half = n / 2;
        half += n & 1;
        for(int i = 0; i < half; i++){
            if(s[i] == '?' and s[n - i - 1] == '?')
                v[i] = -1, v[n - i - 1] = -1;
            else if(s[i] == '?'){
                v[i] = s[n - i - 1] - 'a';
                v[n - i - 1] = v[i];
            }
            else if(s[n - i - 1] == '?'){
                v[i] = s[i] - 'a';
                v[n - i - 1] = v[i];
            }
            else if(s[i] != s[n - i - 1]){
                return -1;
            }
            else{
                v[i] = s[i] - 'a';
                v[n - i - 1] = v[i];
            }
        }
        
        int ans = 0;
        int last = -1;
        
        for(int i = 0; i < half; i++){
            if(v[i] == -1)
                continue;
            
            if(last == -1){
                last = v[i];
                continue;
            }
            
            ans += abs(last - v[i]) * 2;
            last = v[i];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
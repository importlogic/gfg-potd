/*

Author : Manas Rawat
Date : 26/08/2023
Problem : Longest K unique characters substring
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
Video Solution : https://youtu.be/Lc2fO97F_4M

*/


//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int l, r;
        int n = s.size();
        
        l = r = 0;
        
        int ans = -1;
        map<char,int> f;
        
        while(r < n){
            ++f[s[r]];
            
            while(f.size() > k){
                --f[s[l]];
                if(f[s[l]] == 0)
                    f.erase(s[l]);
                    
                ++l;
            }
             
            if(f.size() == k)
                ans = max(ans, r - l + 1);
                
            ++r;
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
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends
/*

Author : Manas Rawat
Date : 04/10/2023
Problem : Roman Number to Integer
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1
Video Solution : NA

*/


//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &s) {
        map<char,int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        
        int ans = 0;
        
        int n = s.size();
        
        for(int i = 0; i < n; i++){
            if(i + 1 < n and mp[s[i]] < mp[s[i + 1]]){
                ans -= mp[s[i]];
            }
            else{
                ans += mp[s[i]];
            }
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
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends
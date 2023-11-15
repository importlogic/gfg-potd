/*

Author : Manas Rawat
Date : 15/11/2023
Problem : Better String
Difficulty : Hard
Problem Link : https://www.geeksforgeeks.org/problems/better-string/1
Video Solution : https://youtu.be/VXEYcAYOaH0

*/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string betterString(string str1, string str2) {
        int n = str1.size();
        
        vector<int> sum(n + 1, 1), last(26, -1);
        
        for(int i = n - 1; i > -1; i--){
            int cur = sum[i + 1];
            int pos = last[str1[i] - 'a'];
            
            if(pos != -1)
                cur -= sum[pos + 1];
                
            last[str1[i] - 'a'] = i;
            sum[i] = sum[i + 1] + cur;
        }
        
        int a = sum[0];
        
        fill(last.begin(), last.end(), -1);
        
        for(int i = n - 1; i > -1; i--){
            int cur = sum[i + 1];
            int pos = last[str2[i] - 'a'];
            
            if(pos != -1)
                cur -= sum[pos + 1];
                
            last[str2[i] - 'a'] = i;
            sum[i] = sum[i + 1] + cur;
        }
        
        int b = sum[0];
        
        return (a >= b) ? str1 : str2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends
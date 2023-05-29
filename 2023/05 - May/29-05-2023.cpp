/*

Author : Manas Rawat
Date : 29/05/2023
Problem : CamelCase Pattern Matching
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/camelcase-pattern-matching2259/1
Video Solution : https://youtu.be/tWB40UvcG18

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string pattern) {
        vector<string> ans;
        for(auto current : Dictionary){
            
            string need = "";
            for(auto i : current)
                if(isupper(i))
                    need += i;
                    
            bool ok = 1;
            if(need.size() < pattern.size())
                continue;
                
            for(int i = 0; i < pattern.size(); i++){
                if(need[i] != pattern[i]){
                    ok = 0;
                    break;
                }
            }
            
            if(ok)
                ans.push_back(current);
        }
        
        if(ans.size() == 0)
            ans.push_back("-1");
            
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
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
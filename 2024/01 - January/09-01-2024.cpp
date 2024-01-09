/*

Author : Manas Rawat
Date : 09/01/2024
Problem : Search Pattern (KMP-Algorithm)
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/search-pattern0205/1
Video Solution : https://youtu.be/nNKBrLePYbc

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            string look = pat + '?' + txt;
            
            vector<int> kmp = prefix_function(look);
            
            vector<int> ans;
            
            int start = 2 * pat.size();
            for(int i = start; i < look.size(); i++){
                if(kmp[i] == pat.size())
                    ans.push_back(i - start + 1);
            }
            
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
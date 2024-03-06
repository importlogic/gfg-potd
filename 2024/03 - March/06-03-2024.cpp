/*

Author : Manas Rawat 
Date : 06/03/2024
Problem : Search Pattern (Rabin-Karp Algorithm)
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1
Video Solution : NA

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string s, string t)
        {
            const int p = 31; 
            const int m = 1e9 + 9;
            int S = s.size(), T = t.size();
        
            vector<long long> p_pow(max(S, T)); 
            p_pow[0] = 1; 
            for (int i = 1; i < (int)p_pow.size(); i++) 
                p_pow[i] = (p_pow[i-1] * p) % m;
        
            vector<long long> h(T + 1, 0); 
            for (int i = 0; i < T; i++)
                h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
            long long h_s = 0; 
            for (int i = 0; i < S; i++) 
                h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 
        
            vector<int> occurrences;
            for (int i = 0; i + S - 1 < T; i++) {
                long long cur_h = (h[i+S] + m - h[i]) % m;
                if (cur_h == h_s * p_pow[i] % m)
                    occurrences.push_back(i + 1);
            }
            return occurrences;
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
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends

/*

Author : Mrpankajpandey
Date : 09/03/2024
Problem :Find the N-th character
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/find-the-n-th-character5925/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    char nthCharacter(string s, int r, int n)
    {
        // code here
        string temp = "";
        while (r--)
        {
            for (auto x : s)
            {
                if (x == '1')
                    temp += "10";
                else
                    temp += "01";
                if (temp.length() > n)
                    break;
            }
            s = temp;
            temp = "";
        }
        return s[n];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends

/*

Author : mrpankajpandey
Date : 14/03/2024
Problem :Largest subsquare surrounded by X
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/largest-subsquare-surrounded-by-x0558/1
Video Solution : NA

*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int largestSubsquare(int n, vector<vector<char>> a)
    {
        // code here
        vector<vector<int>> left(n, vector<int>(n, 0));
        vector<vector<int>> top(n, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == 'X')
                {
                    if (j != 0)
                    {
                        left[i][j] = left[i][j - 1] + 1;
                    }
                    else
                        left[i][j] = 1;
                    if (i != 0)
                    {
                        top[i][j] = top[i - 1][j] + 1;
                    }
                    else
                        top[i][j] = 1;
                }
                int minX = min(top[i][j], left[i][j]);
                while (minX)
                {
                    int k = i - minX + 1;
                    int l = j - minX + 1;
                    if (left[k][j] >= minX and top[i][l] >= minX)
                    {
                        ans = max(ans, minX);
                        break;
                    }
                    minX--;
                }
            }
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
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.largestSubsquare(n, a) << "\n";
    }
}
// } Driver Code Ends

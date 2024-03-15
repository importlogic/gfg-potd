/*

Author : mrpankajpandey
Date : 13/03/2024
Problem :Print matrix in diagonal pattern
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/print-matrix-in-diagonal-pattern/1
Video Solution : NA

*/

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
public:
    vector<int> matrixDiagonally(vector<vector<int>> &mat)
    {
        // Your code here
        vector<int> ans;
        int row = 0, col = 0;
        int n = mat.size();

        while (ans.size() < n * n)
        {
            // going upward diagonally till my first row or my last column is reached    //
            while (row >= 0 && col < n)
            {
                if (row >= 0 && col >= 0 && row < n && col < n)
                {
                    ans.push_back(mat[row][col]);
                    mat[row][col] = 1e9;
                }
                row--;
                col++;
            }
            if (ans.size() == n * n)
            {
                break;
            }

            row = max(row, 0);
            col = min(col, n - 1);

            while (mat[row][col] == 1e9)
            {
                row++;
            }

            // going diagonally downwards
            while (col >= 0 && row < n)
            {
                if (row >= 0 && col >= 0 && row < n && col < n)
                {
                    ans.push_back(mat[row][col]);
                    mat[row][col] = 1e9;
                }
                row++;
                col--;
            }
            if (ans.size() == n * n)
            {
                break;
            }

            row = min(row, n - 1);
            col = max(col, 0);

            while (mat[row][col] == 1e9)
            {
                col++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        int k = 0;
        // cin>>k;
        cin >> n;
        vector<vector<int>> mat(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int> ans = obj.matrixDiagonally(mat);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
}
// } Driver Code Ends
/*

Author : mrpankajpandey
Date : 12/03/2024
Problem :Generalised Fibonacci numbers
Difficulty : Hard
Problem Link : https://www.geeksforgeeks.org/problems/generalised-fibonacci-numbers1820/1
Video Solution : NA

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long mat[3][3], res[3][3];

    void mul(long long res[3][3], long long mat[3][3], long long m)
    {
        long long res1[3][3];
        memset(res1, 0, sizeof(res1));
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    res1[i][j] += (res[i][k] * mat[k][j]);
                    res1[i][j] %= m;
                }
            }
        }

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                res[i][j] = res1[i][j];
    }

    void mat_exp(long long n, long long m)
    {
        while (n > 0)
        {
            if (n & 1)
                mul(res, mat, m);
            mul(mat, mat, m);
            n /= 2;
        }
    }
    long long genFibNum(long long a, long long b, long long c, long long n, long long m)
    {
        // code here
        memset(res, 0, sizeof(res));
        res[0][0] = res[1][1] = res[2][2] = 1;
        mat[0][0] = a;
        mat[0][1] = b;
        mat[0][2] = mat[1][0] = mat[2][2] = 1;
        mat[1][1] = mat[1][2] = mat[2][0] = mat[2][1] = 0;
        if (n <= 2)
            return (1 % m);
        else
        {
            mat_exp(n - 2, m);
            return (res[0][0] + res[0][1] + c * res[0][2]) % m;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, c, n, m;

        cin >> a >> b >> c >> n >> m;

        Solution ob;
        cout << ob.genFibNum(a, b, c, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends
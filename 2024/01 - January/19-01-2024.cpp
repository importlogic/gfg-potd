/*

Author : Manas Rawat
Date : 19/01/2024
Problem : Top k numbers in a stream
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/top-k-numbers3425/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

// } Driver Code Ends

class Solution
{
public:
    vector<vector<int>> kTop(vector<int> &arr, int N, int K)
    {
        vector<int> f(101, 0);

        auto comp = [](pair<int, int> a, pair<int, int> b) -> bool
        {
            if (a.first == b.first)
                return a.second < b.second;

            return a.first > b.first;
        };

        set<pair<int, int>, decltype(comp)> values(comp);
        vector<vector<int>> ans(N);

        for (int i = 0; i < N; i++)
        {
            if (f[arr[i]])
                values.erase({f[arr[i]], arr[i]});

            ++f[arr[i]];

            values.insert({f[arr[i]], arr[i]});

            while (values.size() > K)
            {
                auto ptr = values.end();
                --ptr;

                values.erase(ptr);
            }

            auto ptr = values.begin();

            while (ptr != values.end())
            {
                if (ptr->second > 0)
                    ans[i].push_back((ptr)->second);
                ++ptr;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        vector<int> a(N);
        Array::input(a, N);

        Solution obj;
        vector<vector<int>> res = obj.kTop(a, N, K);

        for (auto it : res)
            Array::print(it);
    }
}

// } Driver Code Ends
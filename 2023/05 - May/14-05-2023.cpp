/*

Author : Manas Rawat
Date : 14/05/2023
Problem : Maximum subset sum
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/e047b92794316450814b29de56cc9c6ec18371b7/1
Video Solution : https://youtu.be/bEnFWlvNpX4

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
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
class Solution {

  public:
    long long findMaxSubsetSum(int N, vector<int> &A) {
        vector<vector<int>> dp(N + 1, vector<int> (2, 0));
        
        for(int i = 1; i < N + 1; i++){
            int x, y;
            x = y = 0;
            
            x = A[i - 1] + dp[i - 1][0]; // take the current element
            y = dp[i - 1][1]; // do not take current element
            
            dp[i][1] = x;
            dp[i][0] = max(x, y);
        }
        
        return dp[N][0];
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
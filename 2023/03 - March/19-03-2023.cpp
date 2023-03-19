/*

Author : Manas Rawat
Date : 19/03/2023
Problem : Distinct Difference
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/c670bf260ea9dce6c5910dedc165aa403f6e951d/1
Video Solution : https://youtu.be/6WLo3HBnlho

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
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
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        vector<int> prefix(N + 2), suffix(N + 2);
        
        prefix[0] = 0;
        set<int> unique;
        for(int i = 1; i <= N; i++){
            unique.insert(A[i - 1]);
            prefix[i] = unique.size();
        }
        
        suffix[N + 1] = 0;
        unique.clear();
        for(int i = N; i > 0; i--){
            unique.insert(A[i - 1]);
            suffix[i] = unique.size();
        }
        
        vector<int> ans(N);
        
        for(int i = 0; i < N; i++){
            ans[i] = prefix[i] - suffix[i + 2];
        }
        
        return ans;
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
        Array::input(A,N);
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends
/*

Author : Manas Rawat
Date : 04/03/2023
Problem : Best Node
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/a3493283697b7b69573a840f371a55ccd9332bb0/1
Video Solution : https://youtu.be/yii_WXbcpzs

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

int finalans;

pair<int,int> dfs(int node, vector<vector<int>> &tree, vector<int> &A){
    int x, y;
    x = y = -1e9;
    
    if(tree[node].size() == 0){
        x = A[node];
        y = A[node] * -1;
    }
    
    for(auto child : tree[node]){
        pair<int, int> ans = dfs(child, tree, A);
        x = max(x, A[node] + ans.second);
        y = max(y, A[node] * -1 + ans.first);
    }
    
    finalans = max(finalans, x);
    
    return {x, y};
}

class Solution {
  public:
    long long bestNode(int N, vector<int> &A, vector<int> &P) {
        vector<vector<int>> tree(N);
    
        for(int i = 1; i < N; i++)
            tree[P[i] - 1].push_back(i);
        
        finalans = -1e9;
        dfs(0, tree, A);
        
        return finalans;
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
        
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
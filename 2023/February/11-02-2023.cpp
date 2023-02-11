/*

Author : Manas Rawat
Date : 11/02/2023
Problem : Minimum Days
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/f4d22b1f9d62e8bee0ff84e9fa51dc66eb5005ec/1
Video Solution : https://youtu.be/QcuvKnAJ0zc

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
    int getMinimumDays(int N,string S, vector<int> &P) {
        set<int> toremove;
        
        for(int i = 0; i < N - 1; i++){
            if(S[i] == S[i + 1]) toremove.insert(i);
        }
        
        int ans = 0;
        for(auto i : P){
            if(toremove.size() == 0) break;
            
            ++ans;
            
            if(i < N - 1 and S[i] == S[i + 1]) toremove.erase(i);
            if(i > 0 and S[i - 1] == S[i]) toremove.erase(i - 1);
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
        string S;cin>>S;
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        int res = obj.getMinimumDays(N,S, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
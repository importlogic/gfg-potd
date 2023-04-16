/*

Author : Manas Rawat
Date : 16/04/2023
Problem : Unequal Arrays
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/4db2fcd97400456c4914d5a3e8ad932cc21e3e9d/1
Video Solution : https://youtu.be/rdrOReUAndU

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
    long long solve(int N, vector<int> &A, vector<int> &B) {
        vector<int> odda, oddb, evena, evenb;
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        for(int i = 0; i < N; i++){
            if(A[i] & 1)
                odda.push_back(A[i]);
            else
                evena.push_back(A[i]);
                
            if(B[i] & 1)
                oddb.push_back(B[i]);
            else
                evenb.push_back(B[i]);
        }
        
        
        if(odda.size() != oddb.size())
            return -1;
            
        int op, pending;
        op = pending = 0;
        
        
        function<void(vector<int>, vector<int>)> dowork = [&](vector<int> a, vector<int> b) {
            for(int i = 0; i < a.size(); i++){
                if(a[i] < b[i]){
                    int dx = (a[i] - b[i]) / 2; // dx will be negative
                    
                    int free = max(pending, dx); // dx is the amount that i want to increase
                    free = min(0, free);
                    pending -= free;
                    dx -= free;
                    
                    op += abs(dx);
                    pending += abs(dx);
                }
                else if(a[i] > b[i]){
                    int dx = (a[i] - b[i]) / 2; // dx will be positive
                    
                    int free = min(pending, dx);
                    free = max(0, free);
                    pending -= free;
                    dx -= free;
                    
                    op += dx;
                    pending -= dx;
                }
            }
        };
        
        dowork(odda, oddb);
        dowork(evena, evenb);
        
        return ((pending == 0) ? op : -1);
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
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
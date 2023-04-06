/*

Author : Manas Rawat
Date : 06/04/2023
Problem : Equal Left and Right Subarray Sum
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/78a6854c8a2915e05f236aa407dfaa1bbc8ae7d3/1
Video Solution : https://youtu.be/qkYBNKXvK38

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
    int equalSum(int N, vector<int> &A) {
        vector<int> prefix(N + 2, 0), suffix(N + 2, 0);
        
        for(int i = 1; i < N + 1; i++)
            prefix[i] = prefix[i - 1] + A[i - 1];
            
        for(int i = N; i > 0; i--)
            suffix[i] = suffix[i + 1] + A[i - 1];
            
        for(int i = 1; i < N + 1; i++){
            if(prefix[i - 1] == suffix[i + 1]){
                return i;
            }
        }
        
        return -1;
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
        int res = obj.equalSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
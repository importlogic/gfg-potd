/*

Author : Manas Rawat
Date : 02/12/2023
Problem : Inorder Traversal and BST
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/inorder-traversal-and-bst5855/1
Video Solution : https://youtu.be/4sSGZ0oUcx8

*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int isRepresentingBST(int arr[], int N)
    {
        for(int i = 1; i < N; i++){
            if(arr[i] <= arr[i - 1])
                return 0;
        }
        
        return 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        cout<<ob.isRepresentingBST(arr,N)<<endl;
    }
    return 0;
}
// } Driver Code Ends
/*

Author : Manas Rawat
Date : 09/07/2023
Problem : Smallest Positive missing number
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1
Video Solution : https://youtu.be/vE-7ZRp_7Zs

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        for(int i = 0; i < n; i++){
            while(arr[i] > 0 and arr[i] < n + 1 and arr[i] != arr[arr[i] - 1])
                swap(arr[i], arr[arr[i] - 1]);
        }
        
        for(int i = 0; i < n; i++){
            if(arr[i] != i + 1)
                return i + 1;
        }
        
        return n + 1;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends
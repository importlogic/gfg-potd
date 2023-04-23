/*

Author : Manas Rawat
Date : 23/04/2023
Problem : Minimum Number
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/7d62c8606123a199720c9b6885249dc9ac651bb7/1
Video Solution : https://youtu.be/5y4hChe5mls

*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minimumNumber(int n,vector<int> &arr){
        int ans = arr[0];
        
        for(int i = 1; i < n; i++)
            ans = __gcd(ans, arr[i]);
            
        return ans;
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.minimumNumber(n,arr)<<endl;
    }
}
// } Driver Code Ends
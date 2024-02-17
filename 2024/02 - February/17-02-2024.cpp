/*

Author : Manas Rawat
Date : 17/02/2024
Problem : Does array represent Heap
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1
Video Solution : https://youtu.be/9dHfhpkGMW4

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        queue<int> q;
        q.push(arr[0]);
        
        for(int i = 1; i < n; i++){
            int big = q.front();
            q.pop();
            
            if(arr[i] > big)
                return 0;
                
            q.push(arr[i]);
                
            if(i + 1 < n){
                if(arr[i + 1] > big)
                    return 0;
                    
                q.push(arr[i + 1]);
                ++i;
            }
        }
        
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends
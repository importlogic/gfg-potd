/*

Author : Manas Rawat
Date : 12/05/2023
Problem : Array Operations
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/3a93b6a25a7b88e4c80a1fee00898fd8022eb108/1
Video Solution : https://youtu.be/tVYMJbrgSOY

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        int ans = 0;
        int current = 0;
        int count = 0;
        
        for(int i = 0; i < n; i++){
            count += arr[i] == 0;
            
            if(arr[i] == 0){
                ans += current > 0;
                current = 0;
                continue;
            }
            
            ++current;
        }
        
        ans += current > 0;
        
        return (count) ? ans : -1;
    }
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
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
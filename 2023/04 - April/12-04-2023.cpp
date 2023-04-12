/*

Author : Manas Rawat
Date : 12/04/2023
Problem : Dominant Pairs
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/2a1c11024ceae36363fc405e07f2fa3e2f896ef0/1
Video Solution : https://youtu.be/nzZuK6j_pOs

*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        map<int,int> mp;
        
        for(int i = 0; i < n / 2; i++)
            mp[arr[i]]++;
            
        auto ptr = mp.end();
        --ptr;
        int current = 0;
        
        while(ptr != mp.begin()){
            (*ptr).second += current;
            current = (*ptr).second;
            --ptr;
        }
        
        (*ptr).second += current;
        
        int ans = 0;
        
        for(int i = n / 2; i < n; i++){
            auto ptr = mp.lower_bound(5 * arr[i]);
            
            if(ptr != mp.end())
                ans += (*ptr).second;
        }
        
        return ans;
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
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends
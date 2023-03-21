/*

Author : Manas Rawat
Date : 21/03/2023
Problem : Taxi Booking
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/7995e41d167d81f14f1d4194b29ef839f52d18ba/1
Video Solution : https://youtu.be/ZQma5hKHeik

*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minimumTime(int N,int cur,vector<int> &pos,vector<int> &time){
        int ans = 1e9;
        
        for(int i = 0; i < N; i++){
            ans = min(ans, abs(cur - pos[i]) * time[i]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,cur;
        cin>>N>>cur;
        vector<int> pos(N),time(N);
        for(int i=0;i<N;i++){
            cin>>pos[i];
        }
        for(int i=0;i<N;i++){
            cin>>time[i];
        }
        Solution ob;
        cout<<ob.minimumTime(N,cur,pos,time)<<endl;
    }
}
// } Driver Code Ends
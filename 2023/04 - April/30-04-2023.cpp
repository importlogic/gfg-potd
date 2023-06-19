/*

Author : Manas Rawat
Date : 30/04/2023
Problem : Powerfull Integer
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/d894706c496da5c5a4f45b0360c7f4164c516f83/1
Video Solution : https://youtu.be/VOHu-ksqn6s

*/


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        map<int,int> start, end;
        
        for(int i = 0; i < n; i++){
            ++start[intervals[i][0]];
            ++end[intervals[i][1]];
        }
        
        int last = 0;
        for(auto &e : start){
            e.second += last;
            last = e.second;
        }
        
        int ans = -1;
        last = 0;
        auto e = end.begin();
        while(e != end.end()){
            end[(*e).first] += last;
            last = (*e).second;
            
            auto endptr = e;
            auto startptr = start.lower_bound((*e).first);
            if(startptr == start.end() or (*startptr).first > (*e).first)
                --startptr;
            
            int started = (*startptr).second;    
            int ended = 0;
            if(endptr != end.begin()){
                --endptr;
                ended = (*endptr).second;
            }
                
            if(started - ended >= k)
                ans = max(ans, (*e).first);
            
            ++e;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
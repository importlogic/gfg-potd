/*

Author : Manas Rawat
Date : 19/02/2024
Problem : Game with String
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/game-with-string4100/1
Video Solution : NA

*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        vector<int> f(26, 0);
        for(auto i : s)
            ++f[i - 'a'];
            
        priority_queue<int> pq;
        for(auto i : f)
            if(i)
                pq.push(i);
                
        while(k-- and pq.size()){
            int x = pq.top();
            pq.pop();
            --x;
            
            if(x)
                pq.push(x);
        }
        
        int ans = 0;
        
        while(pq.size()){
            ans += pq.top() * pq.top();
            pq.pop();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
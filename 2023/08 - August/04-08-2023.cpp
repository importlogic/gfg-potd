/*

Author : Manas Rawat
Date : 04/08/2023
Problem : Reverse a Stack
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/reverse-a-stack/1
Video Solution : https://youtu.be/n7M23F6oDsE

*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void fix(stack<int> &St, queue<int> &q){
        if(St.empty()){
            return;
        }    
        
        q.push(St.top());
        St.pop();
        fix(St, q);
        St.push(q.front());
        q.pop();
    }
    
    void Reverse(stack<int> &St){
        queue<int> q;
        
        fix(St, q);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends
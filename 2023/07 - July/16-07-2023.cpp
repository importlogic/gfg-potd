/*

Author : Manas Rawat
Date : 16/07/2023
Problem : Queue Reversal
Difficulty : Basic
Problem Link : https://practice.geeksforgeeks.org/problems/queue-reversal/1
Video Solution : https://youtu.be/e6y635vOe3o

*/


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//function Template for C++

//Function to reverse the queue.
//function Template for C++

//Function to reverse the queue.
class Solution
{
    public:
    void helper(queue<int> &q){
        if(q.size() == 0)
            return;
            
        int x = q.front();
        q.pop();
        helper(q);
        q.push(x);
    }
    
    queue<int> rev(queue<int> q)
    {   
        helper(q);
        
        return q;
    }
};

//{ Driver Code Starts.
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    Solution ob;
    queue<int> a=ob.rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends
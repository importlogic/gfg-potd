/*

Author : Manas Rawat
Date : 15/07/2023
Problem : Delete middle element of a stack
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1
Video Solution : https://youtu.be/jhWLFTA69NU

*/


//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int toremove = sizeOfStack / 2; 
        
        stack<int> store;
        
        while(toremove--){
            store.push(s.top());
            s.pop();
        }
        
        s.pop();
        
        while(store.size()){
            s.push(store.top());
            store.pop();
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends
/*

Author : Manas Rawat 
Date : 24/03/2024
Problem : Insert an Element at the Bottom of a Stack
Difficulty : Easy 
Problem Link : https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1
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
    stack<int> insertAtBottom(stack<int> st,int x){
        stack<int> t;
        while(st.size()){
            t.push(st.top());
            st.pop();
        }
        
        st.push(x);
        while(t.size()){
            st.push(t.top());
            t.pop();
        }
        
        return st;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n;
        cin>>x;
        stack<int> st;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            st.push(a);
        }
        Solution ob;
        stack<int> tmp=ob.insertAtBottom(st,x);
        vector<int> v;
        while(tmp.size()){
            v.push_back(tmp.top());tmp.pop();
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[i];
            if(i!=v.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends

/*

Author : Manas Rawat
Date : 20/02/2024
Problem : Word Break
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/word-break1352/1
Video Solution : NA

*/


//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Node {
    public:
    unordered_map<char, Node *> next;
    int end;
    
    Node() {
        this -> end = 0;
    }
};

void insert(string &x, Node * root) {
    Node * node = root;
    
    for(auto i : x) {
        if(node -> next[i]){
            node = node -> next[i];
        }
        else{
            Node * new_node = new Node();
            node -> next[i] = new_node;
            node = new_node;
        }
    }
    
    ++(node -> end);
}

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        Node * root = new Node();
        
        for(auto i : B)
            insert(i, root);
        
        int n = A.size();
        vector<bool> dp(n + 1, 0);
        dp[n] = 1;
        
        for(int i = n - 1; i > -1; i--){
            Node * node = root;
            for(int j = i; j < n; j++){
                if(!(node -> next[A[j]]))
                    break;
                    
                node = node -> next[A[j]];
                
                if(node -> end > 0 and dp[j + 1]){
                    dp[i] = 1; 
                    break;
                }
            }
        }
        
        return dp[0];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends
/*

Author : Manas Rawat
Date : 01/05/2023
Problem : Subtree In N-ary Tree
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/079dee7e7db7a784ed73f604e3cf1712432edf79/1
Video Solution : https://youtu.be/hDX-KSz0FUk

*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    vector<Node*> children;
    Node(int val){
        data=val;
    }
};

class N_ary_Tree{
public:
    Node *root;
    int size;
    N_ary_Tree(){
        root=NULL;
        size=0;
    }
    Node *add(int new_key,Node *parent_key=NULL){
        Node *new_node = new Node(new_key);
        if(parent_key == NULL){
            root = new_node;
            size = 1;
        }
        else{
            parent_key->children.push_back(new_node);
            size += 1;
        }
        return new_node;
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int duplicateSubtreeNaryTree(Node *root){
        map<vector<int>, int> f;
        
        function<vector<int>(Node *)> dfs = [&](Node * node) -> vector<int> {
            vector<int> current = { node -> data, -1 };
            
            for(auto child : node -> children){
                vector<int> next = dfs(child);
                for(auto i : next)
                    current.push_back(i);
            }
            
            current.push_back(-1);
            
            ++f[current];
            
            return current;
        };
        
        dfs(root);
        int ans = 0;
        
        for(auto i : f){
            ans += i.second > 1;
        }
            
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        if(i==0){
            string p;
            getline(cin,p);
        }
        string str;
        getline(cin,str);
        stringstream st(str);
        vector<string> s;
        string y;
        while(st>>y){
            s.push_back(y);
        }
        N_ary_Tree *tree = new N_ary_Tree();
        Node *curr;
        queue<Node*> q;
        for(int i=0;i<s.size();i++){
            if (i == 0){
                curr=tree->add(stoi(s[0]));
            }
            else if(s[i] == " "){
                continue;
            }
            else if(q.size() and s[i] == "N"){
                curr = q.front();
                q.pop();
            }
            else if(s[i] != "N"){
                q.push(tree->add(stoi(s[i]), curr));
            }
        }
        Solution ob;
        int res = ob.duplicateSubtreeNaryTree(tree->root);
        cout<<res<<endl;
    }
}
// } Driver Code Ends
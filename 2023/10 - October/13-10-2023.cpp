/*

Author : Manas Rawat
Date : 13/10/2023
Problem : Floor in BST
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/floor-in-bst/1
Video Solution : NA

*/


//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};


// } Driver Code Ends
// Function to search a node in BST.
class Solution{

public:
    int floor(Node* root, int x) {
        int ans = -1;
        
        function<void(Node *)> traverse = [&](Node * cur) {
            if(cur == nullptr)
                return;
                
            if(cur -> data <= x){
                ans = max(ans, cur -> data);
            }  
            
            if(x == cur -> data)
                return;
                
            if(x < cur -> data)
                traverse(cur -> left);
            else
                traverse(cur -> right);
        };
        
        traverse(root);
        
        return ans;
    }
};

//{ Driver Code Starts.

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;
        Solution obj;
        cout << obj.floor(root, s) << "\n";
    }
}

// } Driver Code Ends
/*

Author : Manas Rawat
Date : 19/02/2023
Problem : Fixing Two swapped nodes of a BST
Difficulty : Hard
Problem Link : https://practice.geeksforgeeks.org/problems/6c4053871794c5e7a0817d7eaf88d71c4bb4c2bc/1
Video Solution : https://youtu.be/vHrcfmpWxJQ

*/

//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

bool isBST(Node* n, int lower, int upper) {
    if (!n) return true;
    if (n->data <= lower || n->data >= upper) return false;
    return (isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper));
}

bool compare(Node* a, Node* b, vector<pair<int, int>>& mismatch) {
    if (!a && !b) return true;
    if (!a || !b) return false;

    if (a->data != b->data)
        mismatch.push_back(pair<int, int>(a->data, b->data));

    return (compare(a->left, b->left, mismatch) &&
            compare(a->right, b->right, mismatch));
}


// } Driver Code Ends
// User function Template for C++

/*struct Node
{
    int data;
    struct Node *left, *right;
};*/

void traverse(Node * current, vector<Node*> & inorder){
    if(current == nullptr) return;
    
    traverse(current -> left, inorder);
    inorder.emplace_back(current);
    traverse(current -> right, inorder);
}

class Solution {
  public:
    struct Node *correctBST(struct Node *root) {
        vector<Node *> inorder;
        
        traverse(root, inorder);
        
        Node * first, * second;
        first = second = nullptr;
        
        for(int i = 1; i < inorder.size(); i++){
            if(inorder[i] -> data < inorder[i - 1] -> data){
                if(first == nullptr) first = inorder[i - 1];
                second = inorder[i];
            }
        }
        
        swap(first -> data, second -> data);
        
        return root;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    getchar();

    while (t--) {
        string s;
        getline(cin, s);

        Node* root = buildTree(s);
        Node* duplicate = buildTree(s);

        Solution ob;
        root = ob.correctBST(root);

        // check 1: is tree now a BST
        if (!isBST(root, INT_MIN, INT_MAX)) {
            cout << "0\n";
            continue;
        }

        // check 2: comparing with duplicate tree

        vector<pair<int, int>> mismatch;
        // a vector to store data of mismatching nodes

        if (!compare(root, duplicate, mismatch)) {
            // false output from this function indicates change in structure of
            // tree
            cout << "0\n";
            continue;
        }

        // finally, analysing the mismatching nodes
        if (mismatch.size() != 2 || mismatch[0].first != mismatch[1].second ||
            mismatch[0].second != mismatch[1].first)
            cout << "0\n";
        else
            cout << "1\n";
    }
    return 0;
}

// } Driver Code Ends
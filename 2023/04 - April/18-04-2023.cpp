/*

Author : Manas Rawat
Date : 18/04/2023
Problem : Minimum BST Sum Subtree
Difficulty : Hard
Problem Link : https://practice.geeksforgeeks.org/problems/d064cc0468a5c2bb7817ecd7c1bc59ce25e23613/1
Video Solution : https://youtu.be/XZk3x9vSpUg

*/


//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node *buildTree(string s) {
        if (s.length() == 0 || s[0] == 'N') return NULL;

        // Create the root of the tree
        vector<string> str;
        istringstream iss(s);
        for (string s; iss >> s;) str.push_back(s);
        Node *root = new Node(stoi(str[0]));

        // Push the root to the queue
        queue<Node*> q;
        q.push(root);

        // Starting from the second element
        int i = 1;
        while (q.size() > 0 && i < str.size()) {

            // Get and remove the front of the queue
            Node *currNode = q.front();
            q.pop();

            // Get the current node's value from the string
            string currVal = str[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));
                // Push it to the queue
                q.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= str.size()) break;

            currVal = str[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                q.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


// } Driver Code Ends
//User function Template for C++

struct impdata{
    int min, max, sum;
};

class Solution {
public:
    int minSubtreeSumBST(int target, Node *root) {
        const int inf = 1e9;
        
        queue<Node*> q;
        map<Node*, pair<int,int>> minmax;
        
        function<impdata(Node*, int)> traverse = [&](Node * current, int depth) -> impdata {
            if(current == nullptr){
                impdata newdata;
                newdata.min = inf;
                newdata.max = -inf;
                newdata.sum = 0;
                
                return newdata;
            }
            
            
            impdata left = traverse(current -> left, depth + 1);
            impdata right = traverse(current -> right, depth + 1);
            
            int currentSum = left.sum + right.sum + current -> data;
            if(currentSum == target)
                q.push(current);
                
            impdata newdata;
            newdata.sum = currentSum;
            newdata.min = min({current -> data, left.min, right.min});
            newdata.max = max({current -> data, left.max, right.max});
            
            minmax[current] = {left.max, right.min};
            
            return newdata;
        };
        
        traverse(root, 0);
        int size = 0;
        
        function<bool(Node*)> checkBST = [&](Node * current) -> bool {
            if(current == nullptr)
                return 1;
            
            ++size;
            
            if(minmax[current].first >= current -> data)
                return 0;
                
            if(minmax[current].second <= current -> data)
                return 0;
                
            return checkBST(current -> left) and checkBST(current -> right);
        };
        
        int ans = inf;
        while(q.size()){
            if(checkBST(q.front()))
                ans = min(ans, size);
                
            size = 0;
            q.pop();
        }
        
        return (ans == inf) ? -1 : ans;
    }
};

//{ Driver Code Starts.


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        string str;
        getline(cin,str);
        getline(cin,str);
        Node node(0);
        Node *root = node.buildTree(str);
        Solution ob;
        int res = ob.minSubtreeSumBST(target, root);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends
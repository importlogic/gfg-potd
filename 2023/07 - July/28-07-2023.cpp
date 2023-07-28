/*

Author : Manas Rawat
Date : 28/07/2023
Problem : Lowest Common Ancestor in a BST
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1
Video Solution : https://youtu.be/Hin8FYS_BQc

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree


// } Driver Code Ends
//Function to find the lowest common ancestor in a BST.
class Solution{
    public:
        Node* LCA(Node *root, int n1, int n2)
        {
            vector<Node *> patha, pathb;
            bool founda, foundb;
            founda = foundb = 0;
                
            function<void(Node *)> traverse = [&](Node * node) {
                if(node == nullptr)
                    return;
                    
                if(!founda)
                    patha.push_back(node);
                if(!foundb)
                    pathb.push_back(node);
                    
                if(n1 == node -> data)
                    founda = 1;
                if(n2 == node -> data)
                    foundb = 1;
                    
                traverse(node -> left);
                traverse(node -> right);
                
                if(!founda)
                    patha.pop_back();
                if(!foundb)
                    pathb.pop_back();
            };
            
            traverse(root);
            
            Node * ans = root;
            
            int ind = 0;
            
            while(ind < patha.size() and ind < pathb.size()){
                if(patha[ind] == pathb[ind])
                    ans = patha[ind++];
                else
                    break;
            }
            
            return ans;
        }

};



//{ Driver Code Starts.

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


int main()
{

    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        int l , h;
        getline(cin,s);
        scanf("%d ",&l);
        scanf("%d ",&h);
        Node* root = buildTree(s);
        Solution sol;
        int ans = sol.LCA(root, l, h)->data;
        cout<<ans<<endl;
    }
    return 1;
}
// } Driver Code Ends
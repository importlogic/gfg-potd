/*

Author : Manas Rawat
Date : 23/05/2023
Problem : Construct a Full Binary Tree
Difficulty : Medium
Problem Link : https://practice.geeksforgeeks.org/problems/93c977e771fc0d82e87ba570702732edb2226ad7/1
Video Solution : https://youtu.be/zlHQ_MC8pOY

*/


//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
class Solution{
  public:
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        Node * head = nullptr;
        int pos = size - 1;
        int index = 0;
        
        function<void(Node* &)> construct = [&](Node * &current) {
            if(index == 0){
                current = new Node(pre[index]);
            }
            
            if(current -> data != preMirror[pos]){
                current -> left = new Node(pre[++index]);
                construct(current -> left);
                
                current -> right = new Node(pre[++index]);
                construct(current -> right);
            }
            
            --pos;
        };
        
        construct(head);
        
        return head;
    }
};

//{ Driver Code Starts.

void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    Solution obj;
	    printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends
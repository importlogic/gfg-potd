/*

Author : Manas Rawat
Date : 03/09/2023
Problem : Check if Tree is Isomorphic
Difficulty : Easy
Problem Link : https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1
Video Solution : https://youtu.be/tM7JawvmFEQ

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
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


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1,Node *root2)
    {
        function<bool(Node *, Node *)> dfs = [&](Node * node1, Node * node2) -> bool {
            if(!node1 ^ !node2)
                return 0;
            if(!node1 and !node2)
                return 1;
                
            if(node1 -> data != node2 -> data)
                return 0;
                
            bool ok = 0;
                
            ok = ok or (dfs(node1 -> left, node2 -> left) and dfs(node1 -> right, node2 -> right));
            
            swap(node1 -> left, node1 -> right);
            
            ok = ok or (dfs(node1 -> left, node2 -> left) and dfs(node1 -> right, node2 -> right));
            
            return ok;
        };
        
        return dfs(root1, root2);
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s1,s2;
		getline(cin,s1);
		getline(cin,s2);
		Node* root1 = buildTree(s1);
		Node* root2 = buildTree(s2);
		Solution obj;
		if(obj.isIsomorphic(root1,root2))
		    cout<<"Yes"<<endl;
		else
		    cout<<"No"<<endl;
    }
    return 0;
}

// } Driver Code Ends
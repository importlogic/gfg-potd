/*

Author : Manas Rawat
Date : 06/02/2024
Problem : Node at distance
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/node-at-distance/1
Video Solution : https://youtu.be/aukWM7EI1HI

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}



// Function to Build Tree
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
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//Node Structure
/*struct Node
{
	int k;
	Node *left, *right;
};*/

class Solution
{
    public:
    //Function to return count of nodes at a given distance from leaf nodes.
    int printKDistantfromLeaf(Node* root, int k)
    {
    	vector<Node*> path;
    	unordered_set<Node*> ans;
    	
    	function<void(Node *)> dfs = [&](Node * node) {
    	    if(!node)
    	        return;
    	        
    	    path.push_back(node);
    	        
    	    if(!(node -> left) and !(node -> right)){
    	        int p = (int)path.size() - 1 - k;
    	        
    	        if(p > -1)
    	            ans.insert(path[p]);
    	    }
    	    
    	    dfs(node -> left);
    	    dfs(node -> right);
    	    
    	    path.pop_back();
    	};
    	
    	dfs(root);
    	
    	return ans.size();
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s, ks;
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, ks);
        int k=stoi(ks);
        Solution obj;
        cout<<obj.printKDistantfromLeaf(root, k)<<endl;
    }
    return 0;
}


// } Driver Code Ends
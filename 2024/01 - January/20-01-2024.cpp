/*

Author : Manas Rawat
Date : 20/01/2024
Problem : Distribute candies in a binary tree
Difficulty : Hard
Problem Link : https://www.geeksforgeeks.org/problems/distribute-candies-in-a-binary-tree/1
Video Solution : https://youtu.be/buB9--JjrhU

*/


//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node *left, *right;
};

/* utility that allocates a new Node
   with the given key  */
Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}

Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node* root = newNode(stoi(ip[0]));

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
			currNode->left = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

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
//User function Template for C++

/*
struct Node {
	int key;
	Node *left, *right;
};
*/

class Solution
{
    public:
    int distributeCandy(Node* root)
    {
        map<Node *, int> subtree, candies;
        int ans = 0;
        
        function<void(Node *)> dfs1 = [&](Node * node) {
            if(!node)
                return;
                
            subtree[node] = 1;
            candies[node] = node -> key;
            
            dfs1(node -> left);
            dfs1(node -> right);
            
            subtree[node] += subtree[node -> left] + subtree[node -> right];
            candies[node] += candies[node -> left] + candies[node -> right];
        };
        
        dfs1(root);
        
        function<void(Node *)> dfs2 = [&](Node * node) {
            if(!node)
                return;
            
            int leftextra = candies[node -> left] - subtree[node -> left];
            // if this value is negative it is deficient
            // if this value is positive it has more candies
            
            int rightextra = candies[node -> right] - subtree[node -> right];
            
            ans += abs(leftextra) + abs(rightextra);
            
            dfs2(node -> left);
            dfs2(node -> right);
        };
        
        dfs2(root);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

	int t;
	cin >> t;
	getchar();

	while (t--)
	{

		string str;
		getline(cin, str);

		Node *root = buildTree(str);
		Solution ob;
		cout << ob.distributeCandy(root) << "\n";

	}

	return 0;
}

// } Driver Code Ends
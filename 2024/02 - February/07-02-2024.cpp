/*

Author : Manas Rawat
Date : 07/02/2024
Problem : Min distance between two given nodes of a Binary Tree
Difficulty : Medium
Problem Link : https://www.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1
Video Solution : https://youtu.be/8uhvALQ9sVI

*/


//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

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
        if (i >= ip.size()) break;
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
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*
    1. This code assumes a 0 based tree [ g ] with n vertices.
    2. Set the value of N as the maximum number of vertices in the tree.
    3. Everything has been done you just need to call settingParents and get_lca function.
*/

const int N = 1e5;
const int LOG = log2(N) + 1;
vector<int> def(LOG, -1);

unordered_map<int, vector<int>> up;
unordered_map<int, int> depth;

void settingParents(Node * node, int parent, int d) {
    if(!node)
        return;
        
    int val = node -> data;
    
    up[val] = def;
        
    up[val][0] = parent;
    depth[val] = d;

    for(int i = 1; i < LOG; i++){
        if(up[val][i - 1] != -1)
            up[val][i] = up[up[val][i - 1]][i - 1];
    }

    settingParents(node -> left, node -> data, d + 1);
    settingParents(node -> right, node -> data, d + 1);
}

int get_lca(int x, int y) {
    if(depth[x] < depth[y])
        swap(x, y);

    int dx = depth[x] - depth[y];

    for(int i = LOG - 1; i > -1; i--){
        if((dx >> i) & 1)
            x = up[x][i];
    }

    if(x == y)
        return x;

    for(int i = LOG - 1; i > -1; i--){
        if(up[x][i] != up[y][i]){
            x = up[x][i];
            y = up[y][i];
        }
    }

    return up[x][0];
}

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        settingParents(root, -1, 0);
        
        int lca = get_lca(a, b);
        
        int ans = depth[a] + depth[b] - 2 * (depth[lca]);
        
        return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends
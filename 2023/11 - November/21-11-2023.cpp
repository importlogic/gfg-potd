/*

Author : Manas Rawat
Date : 21/11/2023
Problem : Determine if Two Trees are Identical
Difficulty : Easy
Problem Link : https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
Video Solution : https://youtu.be/4IVNzlbmM0U

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
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
/* A binary tree node


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/


   
class Solution
{
    public:
    bool isSame(Node * r1, Node * r2){
        if((r1 == nullptr) ^ (r2 == nullptr))
            return 0;
        
        return (r1 == nullptr) or (r1 -> data == r2 -> data);
    }
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        bool ok = isSame(r1, r2);
        
        if(r1){
            ok = ok and isIdentical(r1 -> left, r2 -> left) and isIdentical(r1 -> right, r2 -> right);
        }
        
        return ok;
    }
};


//{ Driver Code Starts.

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
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
        if (i >= ip.size())
            break;
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

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string str, str1;
        getline(cin, str);
        Node *rootA = buildTree(str);
        getline(cin, str1);
        Node *rootB = buildTree(str1);
        Solution ob;
        if (ob.isIdentical(rootA, rootB)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
// } Driver Code Ends